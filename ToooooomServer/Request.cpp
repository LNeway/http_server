//
//  Request.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/25.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Request.hpp"
#include <arpa/inet.h>
#include <sys/socket.h>


Request::Request() {
    
}

std::vector<Head> Request::getHeads() {
    return this->headers;
}

Method Request::getMethod() {
    return this->method;
}

void Request::setMethod(Method method) {
    this->method = method;
}

void Request::setHeads(std::vector<Head> heads) {
    this->headers = heads;
}

