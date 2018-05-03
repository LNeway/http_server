//
//  RequestBuild.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/1.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef RequestBuild_hpp
#define RequestBuild_hpp

#include <stdio.h>


#include <stdio.h>
#include <map>
#include "Method.hpp"
#include "Request.hpp"

class RequestBuild {
private:
    Method method;
    std::map<std::string, std::string> heads;
    char* body = NULL;
    int bodyLength;
    std::map<std::string, std::string> params;
    std::string path;
    std::string contentType;
    
public:
    void setRequestMethod(Method method) {
        this->method = method;
    }
    
    void setRequestHeads(std::map<std::string, std::string> heads) {
        this->heads = heads;
    }
    
    void setBody(char* body, int bodyLength) {
        this->body = body;
        this->bodyLength = bodyLength;
    }
    
    void setRequesetParams(std::map<std::string, std::string> params) {
        this->params = params;
    }
    
    void setPath(std::string path) {
        this->path = path;
    }
    
    void setConentType(std::string contentType) {
        this->contentType = contentType;
    }
    
    Request build() {
        Request request;
        request.method = this->method;
        request.headers = this->heads;
        request.body = this->body;
        request.bodyLength = this->bodyLength;
        request.params = this->params;
        request.path = this->path;
        request.contentType = this->contentType;
        return request;
    }
};

#endif /* RequestBuild_hpp */
