#include"mprpcchannel.h"
#include"rpcheader.pb.h"
#include"mprpcapplication.h"
//#include"mprpccontroller.h"
//#include"zookeeperutil.h"
//#include<string>
//#include<errno.h>
//#include<unistd.h>

//网络编程部分
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, 
                          const google::protobuf::Message* request,
                          google::protobuf::Message* response, 
                          google::protobuf::Closure* done)
{
}