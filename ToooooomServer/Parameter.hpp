//
//  Parameter.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/5.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef Parameter_hpp
#define Parameter_hpp


#define TYPE_TEXT 0;
#define TYPE_FILE 1;

#include <stdio.h>
#include "Const.hpp"

class Parameter {

public:
    virtual int getParamType() = 0;
    
    virtual std::string getName() = 0;
    
    virtual void* getValue() = 0;
};

#endif /* Parameter_hpp */
