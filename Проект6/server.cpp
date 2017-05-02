#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <windows.h>
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

		ClientSockets = (SOCKET*)calloc(64,sizeof(SOCKET));

	    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(1997); // не забываем о сетевом порядке!!!
    local_addr.sin_addr.s_addr = 0; // сервер принимает подключения
                                    // на все свои IP-адреса
 
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSocket, (sockaddr *)&local_addr, sizeof(local_addr));
	listen(ListenSocket, SOMAXCONN);

	SOCKET ConnectSocket;
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