#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <thread>

#pragma warning(disable: 4996)
std::vector<SOCKET> Connection;
std::unordered_map<int, SOCKET> ConnectionMap;

void ClientHandler(int idClient) {
    char buffer[128];
    std::string message;
    int bytesRecieved = 0, bytesTotal = 0, terminate = 0;
    while (true) {
        auto itr = ConnectionMap.find(idClient);
        if (itr == ConnectionMap.end()) 
            break;

        while (!terminate)
        {
            memset(buffer, 0, sizeof buffer);
            bytesRecieved = recv(itr->second, buffer, sizeof(buffer) - bytesTotal, NULL);
            //bytesTotal += bytesRecieved;
            //newline character is used to indicate the end of a message
            terminate = (strchr(buffer, '\n') != 0);
            message.append(buffer, bytesRecieved);
            //newline character is replaced with a null terminator to avoid weird characters showing up
            if (terminate) message.replace(message.size() - 1, 1, "\0");
        }
        if (message == "") return;
        std::cout << idClient << " says: " << message << std::endl;
        if (message[0] == '0') {
            std::cout << "close connection " << idClient << "\n";

            closesocket(itr->second);
            ConnectionMap.erase(itr);
            break;
        }

        for (auto element : ConnectionMap) {
          if (element.first != idClient)
            send(element.second, message.c_str(), sizeof(message), NULL);
        }
        message = "";
        terminate = 0;
    }
}

void NewConnectionCreator(const SOCKET& sListen, SOCKADDR_IN& addr, int& addr_size, int client_index)
{
    SOCKET newConnection = accept(sListen, (SOCKADDR*)&addr, &addr_size);
    if (!newConnection) 
        std::cerr << "Error 2" << std::endl;
    else {
        std::cout << "Client Connected!" << std::endl;
        char msg[64] = "Welcome!";
        send(newConnection, msg, sizeof(msg), NULL);
        ConnectionMap.emplace(client_index, newConnection);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler,
            (LPVOID)client_index, NULL, NULL);
    }
}

int main()
{
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2, 1);
    if (WSAStartup(DllVersion, &wsaData) != 0) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    int addr_size = sizeof(addr);

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);
    for (int i = 0; i < 100; i++) {
        NewConnectionCreator(sListen, addr, addr_size, i);
    }

    system("pause");

    return 0;
}