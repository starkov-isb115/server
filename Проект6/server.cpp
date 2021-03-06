#pragma once

#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#define uint8_t byte

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
#include <WinDef.h>

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
	string b;
	string* a = new string[20];
	int t = 0;
	int *c = &t;

int chk(int c)
{
	if ( c == 1 ) exit(1);
}

int von(int c)
{
	if ( c == 1 ) return 1;
	return 0;
}

int func(string s)
{
	char temp;
	
	int m[sizeof(s)];

	int k = 0;

	for ( int k = 0 ; k < sizeof(s);k++ )
	{
		m[k] = ((int)s[k]*k)/sizeof(s);
		cout <<(int)s[k]<<'\n';
	}
	if(((int)s[sizeof(s)-sizeof(s)]+(int)s[sizeof(s)-sizeof(s)+2]+(int)s[5]+(int)s[17]+(int)s[20])/((int)s[1]/25) == ((int)s[0]-4))
		return 0; else return 1;
}

int (*cl)(int) = &chk;
int (*p)(string) = &func;
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
	
		}
}

int ck()
{
	TCHAR s[MAX_PATH];
  DWORD a = 0, b = 0;
   ::GetModuleFileName(::GetModuleHandle(NULL), s, MAX_PATH);
  ::MapFileAndCheckSum(s, &a, &b);
  if ( a != b ) return 1; else 0;
}

int func2(string x)
{
	int m[sizeof(x)];

	int k = 0;
	cout << '\n';
	for ( int k = 0 ; k < sizeof(x);k++ )
	{
		m[k] = ((int)x[k]*k)/sizeof(x);
		cout <<(int)m[k]<<'\n';
	}
	int mt = sizeof(x)-1;


	if ( m[mt-9]*m[mt-8] < m[mt-7]+1)
			{if( m[mt-8-1] > 178 )
				{
					if((m[0]+m[mt])*m[mt-1] == m[mt-2])
					{
						if ( mt > m[5]+m[1]+m[mt-1]-1)
							return 0;
					}
	
			
		}
	}
	return 1;
}

int (*qr)() = &ck;

int main()
{  
	if(IsDebuggerPresent()) exit(1);
	setlocale(0,"RUS");
		string s;
		cin >> s;
		if( p(s) == 1 ) t = 1;
		
	int b = -1;
	
	TCHAR szFullPath[MAX_PATH];
  DWORD dwFileChecksum = 0, dwRealChecksum = 0;
  if (*c == 1) exit(1);
	int *z = &b;
		WSAData Wsadata;
		int res = WSAStartup(MAKEWORD(2, 2), &Wsadata);
		ClientSockets = (SOCKET*)calloc(64,sizeof(SOCKET));
		a = new string[32]; 
	    sockaddr_in local_addr;
		 ::GetModuleFileName(::GetModuleHandle(NULL), szFullPath, MAX_PATH);
  ::MapFileAndCheckSum(szFullPath, &dwFileChecksum, &dwRealChecksum);
    local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(1997);
    local_addr.sin_addr.s_addr = 0; 
	if (dwFileChecksum != dwRealChecksum ) b = 1; else b = 0;
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSocket, (sockaddr *)&local_addr, sizeof(local_addr));
	listen(ListenSocket, SOMAXCONN);

	SOCKET ConnectSocket;
	if ( *z == 1) exit(1);
	for (;; Sleep(75))
	{
		if( ConnectSocket = accept(ListenSocket, NULL, NULL))
		{
			char gm[MAXNAME]; for (int i = 0; i < MAXNAME; i++) gm[i] = 0;	
			recv(ConnectSocket, gm, MAXNAME, NULL);
			cout << gm;
			if (b == 2) exit(1);	
			char *x[sizeof(gm)] = {0};
			char *p = strtok(gm, " ");
			int i = 0;
			while(p)
			{
			 x[i++] = p;
			 p = strtok(NULL, " ");
			}
			string s1 = string(x[1]);
				if( func2(s1) == 1) *c = 1;
			if( von(t) == 1){  closesocket(ConnectSocket); break;}
			if(qr() == 1 ) cl(1);
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