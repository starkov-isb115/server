#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <iostream>


#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define MAX 1000
#define MAXNAME 10

	SOCKET* ClientSockets;
	char UserNames[MAXNAME][MAX];
	int CV = 0;

void msgToClients(SOCKET CS)
{
	char greet[DEFAULT_BUFLEN] = "Hello girls";
	send(CS, greet, sizeof(greet),NULL);
}

void gAs(int vol)
{
	char* get = new char[DEFAULT_BUFLEN];
	while(1)
	{
		char gm[DEFAULT_BUFLEN];
		recv(ClientSockets[vol], gm, sizeof(gm), NULL);
		std::cout << gm;
		for ( int i = 0; i < CV; i++)
		{
			if ( i != vol) send(ClientSockets[i], gm, strlen(gm), NULL);
		}
	}
}

int main(void)
{
	setlocale(LC_ALL,"russian");

	WSAData wsaData;
	WORD sockver = MAKEWORD(2,2);
	if (WSAStartup(sockver, &wsaData) != 0 )
	{
		printf("ошибка при инициализации сокетов");
		exit(1);
	}

	ClientSockets = (SOCKET*)calloc(64,sizeof(SOCKET));

	SOCKADDR_IN address;
	int adresize = sizeof(address);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(1997);
	address.sin_family = AF_INET;

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSocket, (SOCKADDR*)&address, sizeof(address));
	listen(ListenSocket, SOMAXCONN);

	SOCKET ConnectSocket;
	
	while(1)
	{
		if( ConnectSocket = accept(ListenSocket, (SOCKADDR*)&address, &adresize));
		{
			char gm[MAXNAME];
			recv(ConnectSocket, gm, MAXNAME, NULL);
			std::cout << gm;
			for ( int i = 0; i < MAXNAME; i++ )
			{ UserNames[CV][i] = gm[i]; }
			std::cout << "Новый пользователь: " << gm;

			ClientSockets[CV] = ConnectSocket; 
			msgToClients(ConnectSocket);
			CV++;
			CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)gAs,(LPVOID)(CV-1),NULL,NULL);
		}
		
	}
	system("pause");
	closesocket(ListenSocket);
	WSACleanup();

	return 0;
}