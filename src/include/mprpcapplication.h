#pragma once

 #include"mprpcconfig.h"
// #include"mprpccontroller.h"
// #include"mprpcchannel.h"
//mprpc框架的基础类，负责框架的一些初始化操作，使用单例模式设计
class MprpcApplication
{
public:
    static void Init(int argc,char **argv);
    static MprpcApplication& GetInstance();//获取实例
    static MprpcConfig& GetConfig();//获取存储配置的map
private:
    static MprpcConfig m_config;
    MprpcApplication(){};
    MprpcApplication(const MprpcApplication&)=delete;
    MprpcApplication(MprpcApplication&&)=delete;
//单例模式的核心原则
//单例模式的核心是确保一个类只有一个实例，并提供全局访问点。禁止拷贝是实现这一目标的关键技术手段


};