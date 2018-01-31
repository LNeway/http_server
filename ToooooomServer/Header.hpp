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

class Header {
    
private:
    std::string name;
    std::string value;
    
public:
    Header(std::string name, std::string value):name(name), value(value) {
        
    };
    std::string getName();
    std::string getValue();
};

#endif /* Header_hpp */
