# 设置源文件列表（包含当前目录和上级目录的文件）
set(SRC_LIST calluserservice.cc ../user.pb.cc)

add_executable(consumer ${SRC_LIST})

target_link_libraries(provider mprpc protobuf)
