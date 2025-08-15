#aux_source_directory(. SRC_LIST) #当前目录的所有源文件放入SRC_LIST
set(SRC_LIST mprpcapplication.cc mprpcconfig.cc rpcheader.pb.cc rpcprovider.cc)
add_library(mprpc  ${SRC_LIST}) #编译成一个静态库
target_link_libraries(mprpc muduo_net muduo_base pthread)
#这里muduo_base是依赖于muduo_net的，所以要muduo_net要在前面
#由于muduo库是一个.a的库（静态库）所以要把mprpc也编译成一个静态库，需要把shared删去