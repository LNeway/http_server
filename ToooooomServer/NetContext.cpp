//
//  NetContext.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/30.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "NetContext.hpp"
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

NetContext::NetContext(int socket):socket(socket) {
    
}

int NetContext::getSocket() {
    return this->socket;
}

std::string NetContext::getClientAddress() {
    struct sockaddr_in sa;
    unsigned int len = sizeof(sa);
    if (!getpeername(this->socket, (struct sockaddr *)&sa, &len)) {
        return inet_ntoa(sa.sin_addr);
    }
    return NULL;
}
