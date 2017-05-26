#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Imagehlp.h>
#include <tchar.h>
#include "stdafx.h"

#pragma comment(lib, "Imagehlp.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "1997"
#define MAX 1000
#define MAXNAME 100


using namespace std;

	SOCKET ConnectSocket;
	SOCKET ListenSocket;
	SOCKET* ClientSockets;
	string UserNames[MAX];
	int CV = 0;

void gAs(int vol)

{ char *buffer = new char[1024];
		for (;; Sleep(75))
	{	
		memset(buffer, 0, sizeof(buffer)); std::printf(buffer);
		if (recv(ClientSockets[vol], buffer, 1024, NULL))
		{  
			string s = string(buffer); string ans;
			ans= UserNames[vol];ans += ": ";ans+=s;
			const char *cstr = ans.c_str();
			for (int i = 0; i <= CV; i++)
				send(ClientSockets[i], cstr, strlen(cstr), NULL);
		}
		delete buffer;
		}

}

int main()
{
	TCHAR szFullPath[MAX_PATH];
  DWORD dwFileChecksum = 0, dwRealChecksum = 0;

  ::GetModuleFileName(::GetModuleHandle(NULL), szFullPath, MAX_PATH);
	setlocale(LC_ALL, "russian");
		WSAData Wsadata;
		int res = WSAStartup(MAKEWORD(2, 2), &Wsadata);
 ::MapFileAndCheckSum(szFullPath, &dwFileChecksum, &dwRealChecksum);
  if ( dwFileChecksum!=dwRealChecksum ) exit(1);


		ClientSockets = (SOCKET*)calloc(64,sizeof(SOCKET));

	    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(1997);
    local_addr.sin_addr.s_addr = 0; 
                                    
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSocket, (sockaddr *)&local_addr, sizeof(local_addr));
	listen(ListenSocket, SOMAXCONN);

	SOCKET ConnectSocket;
	for (;; Sleep(75))
	{
		if( ConnectSocket = accept(ListenSocket, NULL, NULL))
		{
			char *m = new char[1024];
			for (int i = 0; i < MAXNAME; i++) m[i] = 0; 
			char gm[MAXNAME]; for (int i = 0; i < MAXNAME; i++) gm[i] = 0;
			recv(ConnectSocket, gm, MAXNAME, NULL);
			cout << gm;
			char *x[sizeof(gm)] = {0};
			char *p = strtok(gm, " ");
			int i = 0;
			while(p)
			{
			 x[i++] = p;
			 p = strtok(NULL, " ");
			}
			UserNames[CV] = string(x[0]);
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