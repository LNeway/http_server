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

Request::~Request() {
    if (body != NULL) {
        free(body);
    }
}

std::map<std::string,std::string> Request::getHeads() {
    return this->headers;
}

Method Request::getMethod() {
    return this->method;
}

std::map<std::string, std::string> Request::getParams() {
    return this->params;
}

std::string Request::getPath() {
    return this->path;
}

std::string Request::getContentType() {
    return this->contentType;
}
