# 设置源文件列表（包含当前目录和上级目录的文件）
set(SRC_LIST userservice.cc ../user.pb.cc)

# 创建名为"provider"的可执行文件
add_executable(provider ${SRC_LIST})

target_link_libraries(provider mprpc protobuf)
