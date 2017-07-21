
#ifndef CLIENTSOCKET_HH
#define CLIENTSOCKET_HH

#include "Method.hh"
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class ClientSocket : public Method {

private:
std::string address;
int port;
int sockfd, portno, n;
struct sockaddr_in serv_addr;
struct hostent *server;

char buffer[256];


public:
ClientSocket();
virtual ~ClientSocket();
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

