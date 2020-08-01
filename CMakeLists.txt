PROJECT(zLinux) # 指定工程名称
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2) # 指定最小的版本


# ---------------------------
# 设置一些路径的值
# ---------------------------
set(Project_Root_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# 设置好编译路径
set(Project_Build_DIR ${Project_Root_DIR}/tmp)

# 使用 if else 
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)


# ---------------------------
# toolchain脚本
# ---------------------------


# 需要引入的编译工具脚本
# if(DEFINED CMAKE_TOOLCHAIN_FILE)
if(CMAKE_TOOLCHAIN_FILE)
# CMAKE_TOOLCHAIN_FILE 被指定了，就不用再指定了
else()
# CMAKE_TOOLCHAIN_FILE 没有被指定，加载默认的脚本
SET(CMAKE_TOOLCHAIN_FILE ${Project_Root_DIR}/QemuArmv7ToolChain.cmake)
endif()


# 添加生成动态库的工程路径
# ADD_SUBDIRECTORY(libsrc)



# 设置好动态库发布的路径
set(Lib_Distribution_DIR ${CMAKE_FIND_ROOT_PATH}/lib)
# 设置好头文件的路径
set(Lib_IncludeDistribution_DIR  ${CMAKE_FIND_ROOT_PATH}/include)
# 设置可执行文件的发布路径
# 
message(STATUS "可执行文件发布路径定义在toolchain脚本中" ${EXECUTABLE_Distribution_DIR})
# 添加外部的一些源文件路径
set(Apue_Srcs_DIR  ${Project_Root_DIR}/ApueSrc)

# ---------------------------
# 添加编译时的路径
# ---------------------------

# 添加通用的头文件路径
include_directories(${Lib_IncludeDistribution_DIR})
link_directories(${Lib_Distribution_DIR})

# ---------------------------
# 编译时的一些其他需要修改的东西 
# ---------------------------
# 添加一些需要定义的宏
# ADD_DEFINITIONS(-DLINUX -D_GNU_SOURCE) 
ADD_DEFINITIONS(-DLINUX) 
# 创建编译的临时文件
file(MAKE_DIRECTORY ${Project_Build_DIR})

# ---------------------------
# 最后添加子文件
# ---------------------------

# 1. 首先依赖库
# ADD_SUBDIRECTORY(${Project_Root_DIR}/libsrc ${Project_Build_DIR}/libsrc)

# 2. 添加需要的编译的项目
ADD_SUBDIRECTORY(${Project_Root_DIR}/temp ${Project_Build_DIR}/temp) 







