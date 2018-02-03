//
//  Response.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/29.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef Response_hpp
#define Response_hpp

#include <stdio.h>
#include <vector>
#include "Head.hpp"
#include <map>

class Response {
private:
    int responseCode;
    std::map<std::string, std::string> heads;
    char* body;
public:
    int getResponseCode();
    char* getBody();
    std::vector<Head> getHeaders();
    void writeSocket(int socket);
};

#endif /* Response_hpp */
