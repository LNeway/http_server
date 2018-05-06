//
//  TextParams.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/5.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef TextParams_hpp
#define TextParams_hpp

#include <stdio.h>
#include "Const.hpp"
#include "Parameter.hpp"

class TextParams {
    
private:
    std::string name;
    std::string value;
    int type;

public:
    
    TextParams(std::string name, std::string value, int type);
    
    int getParamType();
    
    std::string getName();
    
    std::string getValue();
};


#endif /* TextParams_hpp */
