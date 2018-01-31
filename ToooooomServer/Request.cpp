//
//  Request.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/25.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Request.hpp"
#include <arpa/inet.h>
#include <sys/socket.h>

Request::Request(int socket) {
    this->socket = socket;
}

int Request::getSocket() {
    return this->socket;
}



