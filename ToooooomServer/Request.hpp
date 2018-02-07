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
#include "Head.hpp"
#include "Method.hpp"
class Request {
private:
    
    std::vector<Head> headers;
    Method method;
    
    void setHeads(std::vector<Head> heads);
    void setMethod(Method method);
    
public:
    Request();
    
    std::vector<Head> getHeads();
    
    Method getMethod();
    
    class Build {
        private:
            Method method;
            std::vector<Head> heads;
        
    public:
        void setRequestMethod(Method method) {
            this->method = method;
        }
        
        void setRequestHeads(std::vector<Head> heads) {
            this->heads = heads;
        }

        Request build() {
            Request request;
            request.setHeads(heads);
            request.setMethod(method);
            return request;
        }
    };
    
};
#endif /* Request_hpp */


