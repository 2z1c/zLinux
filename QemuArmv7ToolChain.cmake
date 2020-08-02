# Qemu 
# https://blog.csdn.net/bytxl/article/details/50635788
# set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_NAME Linux)

# 
SET(CMAKE_C_COMPILER   /root/runlinux/toolcahin/gcc-linaro-5.5.0-2017.10-i686_arm-linux-gnueabi/bin/arm-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER /root/runlinux/toolcahin/gcc-linaro-5.5.0-2017.10-i686_arm-linux-gnueabi/bin/arm-linux-gnueabi-g++)

# 系统根文件系统路径
SET(CMAKE_FIND_ROOT_PATH /root/runlinux/Chapter1/fs)
# 只在 CMAKE_FIND_ROOT_PATH 中查找动态库，以及头文件
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# 可执行文件的发布路径
SET(EXECUTABLE_Distribution_DIR ${CMAKE_FIND_ROOT_PATH}/../share_file)
# https://stackoverflow.com/questions/24648357/compiling-a-static-executable-with-cmake
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBS OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")