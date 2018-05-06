//
//  BadRequest.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/6.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef BadRequest_hpp
#define BadRequest_hpp

#include <stdio.h>
#include <string>

class BadReqeustException {
    
private:
    std::string message;

public:
    
    BadReqeustException(std::string message):message(message) {
        
    }
    
    std::string getMessage() {
        return message;
    }
};

#endif /* BadRequest_hpp */
