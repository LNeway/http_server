//
//  Log.hpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/2/3.
//  Copyright © 2018年 devtom. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>

#include "Const.hpp"

class Log {

public:
    static void d(const std::string& tag, const std::string& message) {
        std::cout<<tag<<" : "<<message<<std::endl;
    }

    
};

#endif /* Log_hpp */
