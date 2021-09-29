#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <netinet/in.h>
#include <iostream>
#include <string>


namespace Base{
namespace NetWork{
class Socket
{
public:

    Socket();
    Socket(const std::string &ip, const std::string &port, int protocal = SOCK_STREAM);
    Socket(int ip, int port, int protocal = SOCK_STREAM);
    int GetSocketFd(){return socket_fd_;}

    int Bind();

    int Listen(int backlog = 5);

    int Connect();

    int Accept();

    int ShutDown(int How = SHUT_RDWR);

    int Close();


private:
    uint32_t socket_fd_;
    int type_;

    std::string ip_str_;
    unsigned int ip_;
    int port_;
    struct sockaddr remote_addr_;
    socklen_t remote_socklen_;
};
}
}