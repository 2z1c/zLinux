# Qemu 
# https://blog.csdn.net/bytxl/article/details/50635788
# set(CMAKE_SYSTEM_NAME Android)

# message(FATAL_ERROR "需要执行交叉编译的 CMAKE_TOOLCHAIN_FILE 文件")
SET(EXECUTABLE_Distribution_DIR ${Project_Build_DIR}/bin)
# 设置好动态库发布的路径
set(Lib_Distribution_DIR ${CMAKE_BINARY_DIR}/lib)
# 设置好头文件的路径
set(Lib_IncludeDistribution_DIR  ${CMAKE_BINARY_DIR}/include)