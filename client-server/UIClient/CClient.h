#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <Windows.h>

#pragma warning(disable: 4996)

ref class CClient
{
public:
  CClient();
  ~CClient();

  BOOL CtrlHandler(DWORD fdwCtrlType);
  void ServerHandler();
  bool connectClient();
  //void disconnectClient();

  void sendMessage(System::String^ messageText);
  void disconnect();

private:
  SOCKET Connection;
  SOCKADDR_IN* addr;
  int addr_size;
};

