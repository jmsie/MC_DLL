#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "UdpSender.h"


extern "C"
{
	void set_up_client()
	{

		WSADATA     wsData;

		WSAStartup(MAKEWORD(2, 2), &wsData);

		struct addrinfo     info;


		ZeroMemory(&info, sizeof(info));
		info.ai_family = AF_INET;
		info.ai_socktype = SOCK_DGRAM;
		info.ai_protocol = IPPROTO_UDP;

		getaddrinfo(NULL, PORT, &info, &pResultC);

		sender_socket = socket(pResultC->ai_family, pResultC->ai_socktype, pResultC->ai_protocol);


		ZeroMemory(&receiver_socket, sizeof(receiver_socket));
		receiver_socket.sin_family = AF_INET;
		receiver_socket.sin_port = htons(atoi(PORT));
		receiver_socket.sin_addr.S_un.S_addr = inet_addr(SERVER);

	}


	void udp_send_text(const char* buffer)
	{
		set_up_client();
		if (sendto(sender_socket, buffer, strlen(buffer), 0, (struct sockaddr*)&receiver_socket, socket_len) == SOCKET_ERROR)
		{
			exit(EXIT_FAILURE);
		}
		close_client();
	}

	void udp_send_order(const char* symbol, const int position, const char* signal)
	{
		set_up_client();
		strncpy_s(order.symbol, symbol, SYMBOL_LEN);
		order.position = position;
		strncpy_s(order.signal, signal, SIGNAL_LEN);
		if (sendto(sender_socket, (const char *)(&order), order_len, 0, (struct sockaddr*)&receiver_socket, socket_len) == SOCKET_ERROR)
		{
			exit(EXIT_FAILURE);
		}
		close_client();
	}

	void close_client()
	{
		freeaddrinfo(pResultC);
		closesocket(sender_socket);
		WSACleanup();
	}


}