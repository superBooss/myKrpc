#include"mprpcapplication.h"
#include<iostream>
#include<unistd.h>

 MprpcConfig MprpcApplication::m_config;
void ShowArgsHelp()
{
    std::cout<<"format: command -i <configfiles>"<<std::endl;
}
void MprpcApplication::Init(int argc,char **argv)
{
    if(argc<2)
/*
argc < 2报错是因为：
•RPC 框架需要配置文件路径才能正常运行
•当只提供程序名（argc == 1）时，无法获取配置
至少需要两个参数程序需要至少 ​2 个参数​：
1.选项标志 -i
2.配置文件路径 <configfiles>
*/
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

     //使用getopt读取参数
    int c=0;
    std::string config_file;//配置选项
    while((c=getopt(argc,argv,"i:"))!=-1)
    {
        switch (c)
        {
        case 'i'://指定选项
            config_file=optarg;
            break;
        case '?'://出现了不想要的参数
            std::cout<<"invalid args"<<std::endl;
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            std::cout<<"need <configfile>"<<std::endl;
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

    //开始加载配置文件了 rpcserver_ip= rpcserver_port zookerper_ip zookeeper_port
    m_config.LoadConfigFile(config_file.c_str());
    std::cout<<"rpcserverip:"<<m_config.Load("rpcserverip")<<std::endl;
    std::cout<<"rpcserverport:"<<m_config.Load("rpcserverport")<<std::endl;
    std::cout<<"zookeeperip:"<<m_config.Load("zookeeperip")<<std::endl;
    std::cout<<"zookeeperport:"<<m_config.Load("zookeeperport")<<std::endl;
}

MprpcApplication& MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;
}

MprpcConfig & MprpcApplication::GetConfig()
{
    return m_config;
}