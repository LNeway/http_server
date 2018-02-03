//
//  Utils.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/2/3.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Request.hpp"

inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

inline Request buildRequest(std::string const &value) {
    Request req;
    return req;
}



