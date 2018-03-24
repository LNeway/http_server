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
    
    
    void setHeads(std::map<std::string, std::string> heads);
    void setParams(std::map<std::string, std::string> params);
    void setMethod(Method method);
    void setBody(char* body, int bodyLength);
    void setPath(std::string path);
    
public:
    Request();
    
    std::map<std::string, std::string> getHeads();
    
    std::string getPath();
    
    std::map<std::string, std::string> getParams();

    
    Method getMethod();
    
    class Build {
        private:
        Method method;
        std::map<std::string, std::string> heads;
        char* body;
        int bodyLength;
        std::map<std::string, std::string> params;
        std::string path;
        
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
        
            Request build() {
                Request request;
                request.setHeads(heads);
                request.setMethod(method);
                request.setBody(body, bodyLength);
                request.setParams(params);
                request.setPath(path);
                return request;
            }
        };
    
};
#endif /* Request_hpp */


