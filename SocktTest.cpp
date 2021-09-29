#include <iostream>
#include <Socket.h>

int main()
{
    Base::NetWork::Socket socket;
    std::cout << socket.GetSocketFd() << std::endl;
    std::cout << "hello server" <<std::endl;
}