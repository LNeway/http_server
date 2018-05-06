//
//  FileParams.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/5.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "FileParams.hpp"

int FileParams::getParamType() {
    return TYPE_FILE;
}

std::string FileParams::getName() {
    return this->name;
}

void* FileParams::getValue() {
    return this->value;
}
