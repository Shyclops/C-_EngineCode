
#ifndef SOCKET_HH
#define SOCKET_HH

#include "Method.hh"
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Socket : public Method {

private:
int port;
std::string address;

fd_set master;    // master file descriptor list
fd_set read_fds;  // temp file descriptor list for select()
int fdmax;        // maximum file descriptor number

int listener;     // listening socket descriptor
struct sockaddr_storage remoteaddr; // client address
socklen_t addrlen;

char remoteIP[INET6_ADDRSTRLEN];

struct timeval tv;

public:
Socket();
virtual ~Socket();
virtual void configure(std::map<std::string, std::string> configList);
virtual const bool canConnect() const;
virtual int establishConnection();
virtual void disconnect();
virtual void read();
virtual void sendData(std::string data);

const int getPort() const;
void setPort(const int port);

const std::string getAddress() const;
void setAddress(const std::string address);
};


#endif

