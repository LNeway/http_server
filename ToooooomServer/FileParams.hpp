//
//  FileParams.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/5.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef FileParams_hpp
#define FileParams_hpp

#include <stdio.h>
#include "Parameter.hpp"
#include "Const.hpp"

class FileParams:public Parameter {
    
private:
    std::string name;
    FILE* value = nullptr;
    
public:
    int getParamType();
    
    std::string getName();
    
    void* getValue();
    
    ~FileParams() {
        if (value != nullptr) {
             fclose(value);
        }
    }
};


#endif /* FileParams_hpp */
