//
//  TextParams.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/5/5.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "TextParams.hpp"

TextParams::TextParams(std::string name, std::string value, int type):name(name), value(value) {
    this->type = type;
}

int TextParams::getParamType() {
    return this->type;
}

std::string TextParams::getName() {
    return this->name;
}

std::string TextParams::getValue() {
    return this->value;
}
