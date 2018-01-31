//
//  NetContext.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/30.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "NetContext.hpp"

int NetContext::getSocket() {
    return this->socket;
}

std::string Request::getClientAddress() {
    struct sockaddr_in sa;
    unsigned int len = sizeof(sa);
    if (!getpeername(this->socket, (struct sockaddr *)&sa, &len)) {
        return inet_ntoa(sa.sin_addr);
    }
    return NULL;
}
