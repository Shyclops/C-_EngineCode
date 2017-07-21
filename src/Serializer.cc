
#include "Serializer.hh"


Serializer::Serializer() {
}

Serializer::~Serializer() {
}

const std::string Serializer::getConfig(std::map<std::string, std::string> configList, std::string key) const {
bool n = configList.count(key);
return (n) ? configList.at(key) : "";
}

