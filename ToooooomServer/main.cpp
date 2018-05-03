//
//  main.cpp
//  ToooooomServer
//
//  Created by Tom Liu on 2018/1/24.
//  Copyright © 2018年 devtom. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <thread>
#include "Request.hpp"
#include "Response.hpp"
#include "NetContext.hpp"
#include "Utils.hpp"
#include <vector>

#define BUFFER_LENGTH 1024
#define REQUEST_END "\r\n\r\n"

using namespace std;

Response handleRequest(Request& request) {
    switch (request.getMethod()) {
        case GET:
            Log::d("handleRequest", "this is a get request....");
            break;
        default:
            break;
    }

    Response resp;
    return resp;
}

int readLine(int fd, char* src, unsigned int maxLength) {
    unsigned int index = 0;
    char c;
    while (index < maxLength) {
        read(fd, &c, 1);
        
        if (c == '\0') {
            break;
        }
        
        if (c == '\r') {
            read(fd, &c, 1);
            if (c == '\n') {
                break;
            } else {
                src[index++] = c;
            }
        } else {
            src[index++] = c;
        }
    }
    return index;
}

void* handleSocket(void* netContext) {
    pthread_detach(pthread_self());

    char buffer[BUFFER_LENGTH];
    NetContext* net = (NetContext*) netContext;
    std::string requestString;
    
    if (net != NULL) {
        long currentLength;
        Request req;
        vector<string> heads;
        
        int count = 0;
        while ((count = readLine(net->getSocket(), buffer, BUFFER_LENGTH)) != 0) {
            string head(buffer,count);
            std::cout<<head<<endl;
            heads.push_back(head);
        }

        vector<string>::iterator itr = heads.begin();
        vector<string>::iterator end = heads.end();
        unsigned int bodyLength = 0;
        string content_type;
        while (itr != end) {
            string head = (*itr);
            vector<string> pair = splitString(head, ": ");
            if (strcasecmp(pair[0].c_str(), "Content-Length") == 0) {
                bodyLength = stoi(pair[1]);
                break;
            }
            ++itr;
        }
    
        char* body = NULL;
        if (bodyLength) {
            body = (char*) malloc(bodyLength);
            read(net->getSocket(), body, bodyLength);
        }
        
        req = buildRequest(heads, body, bodyLength);
        
        for (auto value : req.getParams()) {
            cout<<value.first <<" "<<value.second<<endl;
        }
        
        Log::d("request", "request is done");
        Response resp = handleRequest(req);
        resp.writeSocket(net->getSocket(), "Hello world");
        //cout<<requestString<<endl;
        close(net->getSocket());
        delete net;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = INADDR_ANY;  //具体的IP地址
    serv_addr.sin_port = htons(4000);  //端口
    int result = ::bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (result < 0) {
        cout<<"bind port failed"<<endl;
        return -1;
    }
    //进入监听状态，等待用户发起请求
    while (true) {
        listen(serv_sock, 1024);
        // 接收客户端请求
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        cout<<"listen to client connection"<<endl;
        int clientSocket = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        // cout<<"receive use  \r\n"<<endl;
        // 向客户端发送数据
        pthread_t tid;
        NetContext* netContext = new NetContext(clientSocket);
        int ret = pthread_create(&tid, NULL, handleSocket, (void*)netContext);
        if (ret != 0) {
            cout<<"create a thread failed...."<<endl;
        }
    }
   
    close(serv_sock);
    return 0;
}
