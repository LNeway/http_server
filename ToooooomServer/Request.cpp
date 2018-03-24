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

std::map<std::string,std::string> Request::getHeads() {
    return this->headers;
}

Method Request::getMethod() {
    return this->method;
}

void Request::setMethod(Method method) {
    this->method = method;
}

void Request::setHeads(std::map<std::string,std::string> heads) {
    this->headers = heads;
}

void Request::setBody(char* body, int length) {
    this->body = body;
    this->bodyLength = length;
}

void Request::setParams(std::map<std::string, std::string> params) {
    this->params = params;
}

void Request::setPath(std::string path) {
    this->path = path;
}

std::map<std::string, std::string> Request::getParams() {
    return this->params;
}

std::string Request::getPath() {
    return this->path;
}

void Request::setContentType(std::string contentType) {
    this->contentType = contentType;
}

std::string Request::getContentType() {
    return this->contentType;
}
