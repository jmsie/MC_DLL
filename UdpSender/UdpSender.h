#pragma once

#ifdef UDP_SENDER_H
#define MC_API __declspec(dllexport)
#else
#define MC_API __declspec(dllimport)
#endif
#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>


#pragma comment(lib,"WS2_32")

using namespace std;

#define WIN32_LEAN_AND_MEAN


#define SERVER  "127.0.0.1"
#define PORT    "9999"
#define SYMBOL_LEN 9
#define SIGNAL_LEN 33

extern "C"
{
	//Client
	struct sockaddr_in receiver_socket;
	int socket_len = sizeof(receiver_socket);
	SOCKET  sender_socket;
	struct addrinfo* pResultC;

	typedef struct _Order {
		char symbol[SYMBOL_LEN];
		int position;
		char signal[SIGNAL_LEN];
	} Order;
	static Order order;
	int order_len = sizeof(Order);

	MC_API void  set_up_client();
	MC_API void  udp_send_text(const char* buffer);
	// Symbol[9], position, Signal[33], 
	MC_API void  udp_send_order(const char* symbol, const int position, const char* signal);
	MC_API void  close_client();
}