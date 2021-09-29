#include <Socket.h>
#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout << "Need Input Ip And Port" << std::endl;
        return -1;
    }

    int ip = inet_addr(argv[1]);
    int port = atoi(argv[2]);


    Base::NetWork::Socket socket(ntohl(ip), port);

    std::cout << "Socket fd: " << socket.GetSocketFd() << std::endl;
    if(socket.Connect() < 0)
    {
        std::cout << "Connet Faild" << std::endl;
        return -1;
    }
    std::cout << "Connet Success" <<std::endl;

    while(1)
    {
        std::string sendMsg = "send message";
        std::cout << sendMsg <<std::endl;
        int size = write(socket.GetSocketFd(), sendMsg.c_str(), sendMsg.size());
        std::cout << size << std::endl;
    }
}
