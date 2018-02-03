//
//  NetContext.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/30.
//  Copyright © 2018年 devtom. All rights reserved.
//  一个网络请求的上下文对象
//

#ifndef NetContext_hpp
#define NetContext_hpp

#include <stdio.h>
#include <string>

class NetContext {
    
private:
    int socket;

public:
    NetContext(int socket);
    
    int getSocket();
    
    std::string getClientAddress();
};

#endif /* NetContext_hpp */
