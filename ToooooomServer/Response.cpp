//
//  Response.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/29.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Response.hpp"

char* Response::getBody() {
    return this->body;
}

int Response::getResponseCode() {
    return this->responseCode;
}

std::vector<Header> Response::getHeaders() {
    std::vector<Header> hs;
    std::map<std::string, std::string>::iterator begin = this->headers.begin();
    std::map<std::string, std::string>::iterator end = this->headers.end();
    while (begin != end) {
        Header head(begin->first, begin->second);
        hs.push_back(head);
    }
    return hs;
}
