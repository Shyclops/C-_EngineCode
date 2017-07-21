
#include "ClientSocket.hh"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sstream>


ClientSocket::ClientSocket() : Method() {
this->setPort(8080);
this->setAddress("localhost");
}

ClientSocket::~ClientSocket() {
}

void ClientSocket::configure(std::map<std::string, std::string> configList) {


std::string port, address;
port = this->getConfig(configList, "port");
address = this->getConfig(configList, "address");

if (!port.empty())
this->setPort(atoi(port.c_str()));

if (!address.empty())
this->setAddress(address);

printf("address: %s, port: %d\n", getAddress().c_str(), getPort());
}

const bool ClientSocket::canConnect() const {
return true;
}

int ClientSocket::establishConnection() {


int result = -1;

sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) 
perror("ERROR opening socket");
server = gethostbyname(this->getAddress().c_str());

if (server == NULL) {
perror("ERROR, no such host\n");
exit(0);
}

bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr, 
(char *)&serv_addr.sin_addr.s_addr,
server->h_length);
serv_addr.sin_port = htons(this->getPort());


if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
perror("ERROR connecting\n");

return result;

}

void ClientSocket::disconnect() {
}

void ClientSocket::read() {
}

void ClientSocket::sendData(std::string data) {
write(sockfd,data.c_str(),data.length());
}

const int ClientSocket::getPort() const {
return this->port;
}

void ClientSocket::setPort(const int port) {
this->port = port;
}

const std::string ClientSocket::getAddress() const {
return this->address;
}

void ClientSocket::setAddress(const std::string address) {
this->address = address;
}

