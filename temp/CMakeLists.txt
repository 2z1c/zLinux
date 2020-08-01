PROJECT(helloword) # 指定工程名称
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2) # 指定最小的版本
AUX_SOURCE_DIRECTORY(. DIR_SRCS) # 同步当前文件夹的所有文件到 DIR_SRCS 变量
# 找到动态库

ADD_EXECUTABLE(main.run ${DIR_SRCS}) # 生成可执行文件,个人原因，喜欢在编译的可执行文件后面加上后缀
target_link_libraries(main.run)