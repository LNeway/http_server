//
//  Utils.h
//  ToooooomServer
//
//  Created by Tom Liu on 2018/2/3.
//  Copyright © 2018年 devtom. All rights reserved.
//

#include "Const.hpp"
#include <regex>
#include "RequestBuild.hpp"

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
    
    if (value.length()) {
        vector.push_back(value);
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


/**
 build request from the params.

 @param heads <#heads description#>
 @param body <#body description#>
 @param bodyLength <#bodyLength description#>
 @return <#return value description#>
 */
static Request buildRequest(std::vector<std::string> heads, char* body, unsigned int bodyLength) {
    std::vector<std::string>::iterator begin = heads.begin();
    std::vector<std::string>::iterator end = heads.end();
    RequestBuild build;
    std::map<std::string, std::string> headsMap;
    bool isMethodLine = true;
    int emptyCount =  0;
    Method method;
    std::string path;
    while (begin != end) {
        if (isMethodLine) {
            std::vector<std::string> methodV = splitString(*begin, " ");
            std::string methodStr = methodV[0];
            path = methodV[1];
            std::map<std::string, Method>::iterator it = allMethod.find(methodStr);
            if (it == allMethod.end()) {
                Log::d("method", "unspported method");
            } else {
                method = it->second;
                build.setRequestMethod(it->second);
            }
            isMethodLine = false;
        } else if (emptyCount != 1) { // deal with the request heads;
            if (trim(*begin).length() == 0) {
                ++emptyCount;
                continue;
            }
            std::vector<std::string> heads = splitString(*begin, ": ");
            headsMap.insert(std::pair<std::string, std::string>(heads[0], heads[1]));
        } else { // deal with request body.
            Log::d("reqeustBody", "this is request body");
        }
        ++begin;
    }
    
    std::vector<std::string> pathV = splitString(path, "?");
    if (pathV.size() == 1) {
        build.setPath(pathV[0]);
    }
    
    std::map<std::string, std::string> params;
    
    if (pathV.size() == 2) {
        std::string queryString = pathV[1];
        std::vector<std::string> pairs = splitString(queryString, "&");
        std::vector<std::string>::iterator begin = pairs.begin();
        std::vector<std::string>::iterator end = pairs.end();
        while(begin != end) {
            std::vector<std::string> pairs = splitString(*begin, "=");
            if (pairs.size() == 2) {
                params.insert(std::pair<std::string, std::string>(pairs[0], pairs[1]));
            }
            ++begin;
        }
    }
    
    if (method == POST) {
        std::map<std::string, std::string>::iterator contentTypeIt = headsMap.find(CONTENT_TYPE);
        if (contentTypeIt != headsMap.end()) {
            std::string contentType = contentTypeIt->second;
            std::vector<std::string> types = splitString(contentType, "; ");
            if (types.size() == 1) {
                build.setConentType(types[0]);
            }
            
            // parse the body boundary,get request data in the body.
            if (types.size() == 2) {
                std::vector<std::string> boundary = splitString(types[1], "=");
                if (boundary.size() == 2) { // find the body data boundary
                    std::string boundaryStr = "--"+boundary[1];
                    if (bodyLength > boundaryStr.length()) {
                        std::string pattern = boundaryStr + "[\\s\\S]*?" + boundaryStr; //
                        std::regex re(pattern);
                    
                        std::string bodyStr(body);
                        std::smatch results;
                        std::vector<std::string> dataPart;
                        while (std::regex_search(bodyStr, results, re)) {
                            std::string s;
                            for (std::string x : results) {
                                s += x;
                            }
                            s.erase(0, boundaryStr.length());
                            s.erase(s.length() - boundaryStr.length(), s.length());
                            dataPart.push_back(s);
                            bodyStr = boundaryStr + results.suffix().str();
                        }
                        
                        for (std::string data : dataPart) {
                            std::vector<std::string> lines = splitString(data, "\r\n");
                            if (lines.size() != 4) {
                                continue;
                            }
                            
                            std::string kp = "name=[\\s\\S]*";
                            std::regex kr(kp);
                            std::smatch km;

                            
                            if (std::regex_search(lines[1], km, kr)) {
                                std::string keyValue = *km.begin();
                                std::vector<std::string> kv = splitString(keyValue, "=");
                                if (kv.size() == 2) {
                                    params.insert(std::pair<std::string, std::string>(kv[1], lines[3]));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    build.setRequesetParams(params);
    build.setRequestHeads(headsMap);
    if (bodyLength) {
        build.setBody(body, bodyLength);
    }
    return build.build();
}

#endif /* Utils_h */
