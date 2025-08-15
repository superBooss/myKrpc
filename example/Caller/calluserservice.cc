#include<iostream>
#include"mprpcapplication.h"
#include"user.pb.h"
#include"mprpcchannel.h"

int main(int argc,char **argv)
{
    //整个程序启动以后，想使用mprpc来获取rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
    MprpcApplication::Init(argc,argv);

    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel);

    //rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhangsan");
    request.set_pwd("123");

    //rpc方法的响应
    fixbug::LoginResponse response;
    //发起rpc方法的调用，同步的rpc调用过程，MprpcChannel::callmethod
    stub.Login(nullptr,&request,&response,nullptr);
    
    //stub.Login();//RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送



    return 0;
}