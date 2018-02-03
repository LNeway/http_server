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
    
public:
    std::vector<Head> getHeads();
    
    Method getMethod();
    
};
#endif /* Request_hpp */


