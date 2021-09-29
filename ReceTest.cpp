
#include <Socket.h>
#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Need Input  Port" << std::endl;
        return -1;
    }

    //std::string ip(argv[1]);
    std::string port(argv[1]);

    Base::NetWork::Socket socket(ntohl(INADDR_ANY), atoi(port.c_str()));

    std::cout << "Socket fd: " << socket.GetSocketFd() << std::endl;

    if(socket.Bind() < 0)
    {
        std::cout << "Bind Faild" << std::endl;
        return -1;
    }
    std::cout << "Bind sucess" << std::endl;

    if(socket.Listen() < 0)
    {
        std::cout << "Listen Faild" << std::endl;
        return -1;
    }

    std::cout << "start listen" << std::endl;

    while(1)
    {
        std::cout << "wait accept" << std::endl;
        int accept_fd = socket.Accept();
        if(accept_fd < 0)
        {
            std::cout << "Accept error" << std::endl;
            continue;
        }
        std::cout << "have a connection fd:" << accept_fd <<  std::endl;
        char buf[4096];
        while(1){
        int size = recv(accept_fd,buf,4096,0);
        std::cout << "read size:" << size << " " <<  buf << std::endl;
        }
    }
}