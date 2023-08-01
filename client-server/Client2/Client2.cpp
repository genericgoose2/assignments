// Client2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#include <iostream>

#pragma warning(disable: 4996)

SOCKET Connection;

void ServerHandler() {
    char message[128];
    while (true) {
        recv(Connection, message, sizeof(message), NULL);
        std::cout << message << std::endl;
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

    Connection = socket(AF_INET, SOCK_STREAM, NULL);

    if (connect(Connection, (SOCKADDR*)&addr, addr_size)) {
        std::cerr << "Error 2" << std::endl;
        return 1;
    }
    std::cout << "Connection Succsess!" << std::endl;

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ServerHandler, NULL, NULL, NULL);
    char message[128];
    while (true) {
        std::cin.getline(message, sizeof(message));
        send(Connection, message, sizeof(message), NULL);
        if (message == "exit") {
            break;
        }
        Sleep(10);
    }

    std::cout << "Hello World!\n";
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
