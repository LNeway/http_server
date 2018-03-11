//
//  Utils.h
//  ToooooomServer
//
//  Created by Tom Liu on 2018/2/3.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Const.hpp"

#ifndef Utils_h
#define Utils_h

static std::map<std::string, Method> allMethod = {
    {"POST", POST},
    {"GET", GET},
    {"HEAD", HEAD},
    {"PUT", PUT},
    {"DELETE", DELETE},
    {"OPTIONS", OPTIONS}
};

inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

static std::vector<std::string> splitString(std::string value, std::string const &delimiter) {
    size_t pos;
    std::string token;
    size_t delLength = delimiter.length();
    std::vector<std::string> vector;
    while((pos = value.find(delimiter)) != std::string::npos) {
        vector.push_back(value.substr(0, pos));
        value.erase(0, pos + delLength);
    }
    return vector;
}


/**
 返回去掉空格之后的字符串

 @param str <#str description#>
 @return <#return value description#>
 */
static std::string trim(const std::string str)
{
    std::size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

static Request buildRequest(std::string const &value) {
    std::vector<std::string> lines = splitString(value, NEW_LINE);
    std::vector<std::string>::iterator begin = lines.begin();
    std::vector<std::string>::iterator end = lines.end();
    Request::Build build;
    std::vector<Head> headsVector;
    bool isMethodLine = true;
    int emptyCount =  0;
    while (begin != end) {
        if (isMethodLine) {
            std::vector<std::string> methodV = splitString(*begin, " ");
            std::string methodStr = methodV[0];
            std::map<std::string, Method>::iterator it = allMethod.find(methodStr);
            if (it == allMethod.end()) {
                Log::d("method", "unspported method");
            } else {
                build.setRequestMethod(it->second);
            }
            isMethodLine = false;
        } else if (emptyCount != 1) { // deal with the request heads;
            if (trim(*begin).length() == 0) {
                ++emptyCount;
                continue;
            }
            std::vector<std::string> heads = splitString(*begin, ":");
            Head head(heads[0],heads[1]);
            headsVector.push_back(head);
        } else { // deal with request body.
            Log::d("reqeustBody", "this is request body");
        }
        ++begin;
    }
    build.setRequestHeads(headsVector);
    return build.build();
}

#endif /* Utils_h */
