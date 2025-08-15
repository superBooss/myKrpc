#include<iostream>
#include<string>
#include"../user.pb.h"
#include "mprpcapplication.h"
#include"rpcprovider.h"
using namespace fixbug;
/*
UserService原来是一个本地服务，提供了两个进程内的本地方法Login和GetFriendList
*/

class UserService:public fixbug::UserServiceRpc//使用在rpc服务发布端（rpc服务提供者)
{
public:
    //登入系统的方法
    bool Login(std::string name,std::string pwd)
    {
        std::cout<<"doing local service:Login"<<std::endl;
        std::cout<<"name:"<<name<<" pwd"<<pwd<<std::endl;
        return true;
    }
    /*
    重写基类userserviceRpc的虚函数 下面这些方法都是框架直接调用的
    1.caller ==> Login(LoginRequest) => muduo => callee
    2.callee ==> Login(LoginRequest) =>交到下面重写的Login方法
    */
   
    void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        //框架给业务上报了请求参数LoginRequest ，业务获取相应数据做本地业务
        std::string name=request->name();
        std::string pwd=request->pwd();

        bool login_result=Login(name,pwd);//做本地业务

        //把响应写入LoginResponse
        fixbug::ResultCode *code=response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response ->set_success(login_result);

        //执行回调操作  执行响应对象数据的序列化和网络发送（都是由框架完成）
        done->Run();
    }

};

int main(int argc,char**argv)
{
    //先调用框架的初始化操作 provider -i config.conf，从init方法读取配置服务，比如IP地址和端口号
    MprpcApplication::Init(argc,argv);

    //项目提供者，让我们可以发布该服务
    RpcProvider provider;
    //provider是一个rpc网络服务对象。把UserService对象发布到rpc节点上
    provider.NotifyService(new UserService());
    
    //启动一个rpc服务发布节点，run以后，进程进入阻塞状态，等待远程的rpc请求
    provider.Run();

    return 0;
}