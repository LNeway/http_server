//
//  Request.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/25.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef Request_hpp
#define Request_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "Head.hpp"
#include "Method.hpp"
class Request {
private:
    
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> params;
    Method method;
    char* body;
    int bodyLength;
    std::string path;
    std::string contentType;
    
public:
    Request();
    
    friend class RequestBuild;
    
    ~Request();
    
    std::map<std::string, std::string> getHeads();
    
    std::string getPath();
    
    std::map<std::string, std::string> getParams();
    
    std::string getContentType();

    Method getMethod();

    
};


#endif /* Request_hpp */


