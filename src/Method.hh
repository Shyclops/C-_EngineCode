
#ifndef METHOD_HH
#define METHOD_HH

#include <map>
#include <string>

class Method {

public:
Method();
virtual ~Method();
virtual void configure(std::map<std::string, std::string> configList) = 0;
virtual const bool canConnect() const;
virtual int establishConnection() = 0;
virtual void disconnect() = 0;
virtual void read() = 0;
virtual void sendData(std::string) = 0;
virtual const std::string getConfig(std::map<std::string, std::string> configList, std::string key) const;
};


#endif

