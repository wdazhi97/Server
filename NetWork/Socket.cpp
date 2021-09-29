#include <Socket.h>
#include <CommonDef.h>
#include <string.h>

using namespace Base::NetWork;


Socket::Socket()
{
    type_ = SOCK_STREAM;
    socket_fd_ = -1;
}

Socket::Socket(const std::string & ip, const std::string & port, int type):type_(type)
{
    socket_fd_ = socket(AF_INET, type, 0);
    if(socket_fd_ < 0)
    {
        PRINT_ERROR(Socket);
    }
    ip_str_ = ip;
    struct in_addr socket_address;
    if(inet_aton(ip.c_str(), &socket_address) < 0)
    {
        PRINT_ERROR(Socket::inet_aton)
    }
    ip_ = socket_address.s_addr;
    port_ = atoi(port.c_str());
}

Socket::Socket(int ip, int port, int type):type_(type),port_(port),ip_(ip)
{
    socket_fd_ = socket(AF_INET, type, 0);
    if(socket_fd_ < 0)
    {
        PRINT_ERROR(Socket)
    }
    ip_str_ = inet_ntoa(in_addr{ip_});
}


int Socket::Bind()
{
    struct sockaddr_in socket_addr;
    bzero(&socket_addr, sizeof(sockaddr_in));
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_port = htons(port_);
    socket_addr.sin_addr.s_addr = htonl(ip_);
    
    if(bind(socket_fd_, (sockaddr*)(&socket_addr), sizeof(sockaddr)) < 0)
    {
        PRINT_ERROR(Bind)
        return -1;
    }
    return 0;
}


int Socket::Listen(int backlog)
{
    if(listen(socket_fd_,backlog) < 0)
    {
        PRINT_ERROR(Listen)
        return -1;
    }
    return 0;
}

int Socket::Connect()
{
    struct sockaddr_in socket_addr;
    bzero(&socket_addr, sizeof(sockaddr_in));

    std::cout << "port: " << port_ << "ip: " << ip_ << std::endl;
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_port = htons(port_);
    socket_addr.sin_addr.s_addr = htonl(ip_);
   
    if(connect(socket_fd_, (sockaddr*)(&socket_addr),sizeof(sockaddr)) < 0)
    {
        PRINT_ERROR(Connect)
        return -1;
    }
    return 0;
}

int Socket::Accept()
{
    int accept_fd = 0;
    
    if((accept_fd = accept(socket_fd_, &remote_addr_, &remote_socklen_) )< 0)
    {
        PRINT_ERROR(Accept)
        return -1;
    }
    return accept_fd;
}


int Socket::ShutDown(int how)
{
    if(shutdown(socket_fd_, how) < 0)
    {
        PRINT_ERROR(ShutDown)
        return -1;
    }
    return 0;
}


int Socket::Close()
{
    if(close(socket_fd_) < 0)
    {
        PRINT_ERROR(Close)
        return -1;
    }
    return 0;
}