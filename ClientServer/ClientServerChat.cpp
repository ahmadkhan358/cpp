#include<iostream>
#include<conio.h>
#include<WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

void main() {
	//Initialize winsock
	WSADATA wsdata;
	WORD ver = MAKEWORD(2, 2);
	int wsOK = WSAStartup(ver, &wsdata);
	if (wsOK != 0) {
		cerr << "Can't initialize winsock, Quitting" << endl;
		return;
	}

	//Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		cerr << "Can't create a socket, Quitting" << endl;
		return;
	}

	//Bind an ip and port to socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; //Could also use inet_pton
	bind(listening, (sockaddr*)&bind, sizeof(hint));

	//Tell winsock the socket is for listening
	listen(listening, SOMAXCONN);

	//Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST]; //client's remote name
	char service[NI_MAXSERV]; //service (i.e port) the client is connect on

	ZeroMemory(host, NI_MAXHOST); //Same as memset(host, 0, IN_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		cout << host << " connected on port " << service << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
	}

	//Close listening socket
	closesocket(listening);

	//While loop: accept and echo message back to client
	char buff[4096];
	while (true) {
		ZeroMemory(buff, 4096);

		//Wait for client to send data
		int byteReceived = recv(clientSocket, buff, 4096, 0);
		if (byteReceived == SOCKET_ERROR) {
			cerr << "Error in receiving, Quitting" << endl;
			break;
		}

		if (byteReceived == 0) {
			cout << "Client disconnected" << endl;
			break;
		}

		//Echo message back to client
		send(clientSocket, buff, byteReceived + 1, 0);
	}

	//Close the socket
	closesocket(clientSocket);

	//Cleanup winsock
	WSACleanup();

	_getch();
}