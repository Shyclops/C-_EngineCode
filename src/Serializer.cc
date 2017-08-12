
#include "Serializer.hh"


/*
* Serializer.cc
*
*  Created on: Jun 29, 2017
*      Author: nicolas
*/

#include "Serializer.hh"

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

const std::string Serializer::getConfig(
std::map<std::string, std::string> configList, std::string key) const {
bool n = configList.count(key);
return (n) ? configList.at(key) : "";
}

