
#include "Method.hh"


/*
* Method.cc
*
*  Created on: Jun 29, 2017
*      Author: nicolas
*/

#include "Method.hh"
#include <stdio.h>

Method::Method() {
}

Method::~Method() {
}

const bool Method::canConnect() const {
return false;
}

const std::string Method::getConfig(
std::map<std::string, std::string> configList, std::string key) const {
bool n = configList.count(key);
return (n) ? configList.at(key) : "";
}

