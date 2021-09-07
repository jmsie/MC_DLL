// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
/*
* DLL turtorial https://docs.microsoft.com/zh-tw/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160
*/
#include <iostream>
#include "MathLibrary.h"
#include "UdpSender.h"

int main()
{
	//udp_send_text("Test\n");
	udp_send_order("TXFH1", -2, "TEST_");
}
