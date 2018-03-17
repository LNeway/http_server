//
//  Response.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/29.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Response.hpp"
#include <unistd.h>
#include "Const.hpp"

char* Response::getBody() {
    return this->body;
}

int Response::getResponseCode() {
    return this->responseCode;
}

std::vector<Head> Response::getHeaders() {
    std::vector<Head> hs;
    std::map<std::string, std::string>::iterator begin = this->heads.begin();
    std::map<std::string, std::string>::iterator end = this->heads.end();
    while (begin != end) {
        Head head(begin->first, begin->second);
        hs.push_back(head);
    }
    return hs;
}

void Response::writeSocket(int socket, std::string content) {
    //std::string contentLength = heads[CONTENT_LENGTH];
    //int length = stoi(contentLength);
    std::string bd = "HTTP/1.1 ";
    bd += std::to_string(200);
    bd += NEW_LINE;
    bd += "Content-Type: text/html;charset=ISO-8859-1";
    bd += NEW_LINE;
    bd += "Content-Length:";
    bd += content.length();
    bd += NEW_LINE;
    bd += NEW_LINE;
    bd += content;
    write(socket, bd.c_str(), bd.length());
}

