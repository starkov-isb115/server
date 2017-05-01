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
#define DEFAULT_PORT "1997"
#define MAX 1000
#define MAXNAME 10

	SOCKET ConnectSocket;
	SOCKET ListenSocket;
	SOCKET* ClientSockets;
	char UserNames[MAXNAME][MAX];
	int CV = 0;

void gAs(int vol)
{
	while(1)
	{
		for (;; Sleep(75))
	{
		char *buffer = new char[1024];
		memset(buffer, 0, sizeof(buffer)); std::printf(buffer);
		if (recv(ClientSockets[vol], buffer, 1024, NULL))
		{
			for (int i = 0; i <= CV; i++)
				send(ClientSockets[i], buffer, strlen(buffer), NULL);
		}

		delete buffer;
	}
	}
}


int main(void)
{
	setlocale(LC_ALL, "russian");
		WSAData Wsadata;
		int res = WSAStartup(MAKEWORD(2, 2), &Wsadata);
		if (res != 0) { return 0; }
struct addrinfo hints;
		struct addrinfo * result;

		ClientSockets = (SOCKET*)calloc(64, sizeof(SOCKET));
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_flags = AI_PASSIVE;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		int iResult;
		iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	
		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	
		iResult = bind(ListenSocket, result->ai_addr, result->ai_addrlen);
		
		listen(ListenSocket, SOMAXCONN);
		freeaddrinfo(result);

	for (;; Sleep(75))
	{
		if( ConnectSocket = accept(ListenSocket, NULL, NULL));
		{
			char gm[MAXNAME]; for (int i = 0; i < MAXNAME; i++) gm[i] = 0;
			recv(ConnectSocket, gm, MAXNAME, NULL);
			std::cout << gm;
			for ( int i = 0; i < MAXNAME; i++ )
			{ UserNames[CV][i] = gm[i]; }
			std::cout << "Iiaue iieuciaaoaeu: " << gm;

			ClientSockets[CV] = ConnectSocket; 
			CV++;
			CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)gAs,(LPVOID)(CV-1),NULL,NULL);
		}
		
	}
	system("pause");
	closesocket(ListenSocket);
	WSACleanup();

	return 0;
}