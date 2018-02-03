//
//  Header.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/29.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef Header_hpp
#define Header_hpp

#include <stdio.h>
#include <string>

const std::string CONTENT_LENGTH = "content-length";

class Head {
    
private:
    std::string name;
    std::string value;
    
public:
    Head(std::string name, std::string value):name(name), value(value) {
        
    };
    std::string getName();
    std::string getValue();
};

#endif /* Header_hpp */
