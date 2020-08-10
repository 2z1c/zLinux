PROJECT(zApueLibMemcpy) # 指定工程名称
# 指定源文件
AUX_SOURCE_DIRECTORY(. DIR_SRCS) # 同步当前文件夹的所有文件到 DIR_SRCS 变量

# 添加头文件
SET(DIR_Headers zMemcpy.h)

include_directories(.)

# 生成静态库
Set(LIB_STATIC_NAME zMemcpy)
Set(__LIB_STATIC_NAME lib${LIB_STATIC_NAME}.a)


add_library(${LIB_STATIC_NAME} STATIC ${DIR_Headers} ${DIR_SRCS} )

#------------------------
# 发布文件
#------------------------
# 设置好路径，准备将静态库复制发布文件中
# 复制库
add_custom_command(TARGET ${LIB_STATIC_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        copy "${CMAKE_CURRENT_BINARY_DIR}/${__LIB_STATIC_NAME}"
        "${Lib_Distribution_DIR}/${__LIB_STATIC_NAME}"
        COMMENT "Copying ${__LIB_STATIC_NAME} to ${Lib_Distribution_DIR} directory")

# copy out lib header file...
# 开始遍历，生成对应的可执行文件
FOREACH(__DIR_Headers ${DIR_Headers})
#   message(STATUS ${__DIR_Headers})
#   file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${__DIR_Headers} DESTINATION ${Lib_IncludeDistribution_DIR}/${__DIR_Headers})
  add_custom_command(TARGET ${LIB_STATIC_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        copy "${CMAKE_CURRENT_SOURCE_DIR}/${__DIR_Headers}"
        "${Lib_IncludeDistribution_DIR}/${__DIR_Headers}"
        COMMENT "Copying ${LIB_STATIC_NAME} header to ${Lib_IncludeDistribution_DIR} directory")
ENDFOREACH(__DIR_Headers)

# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${DIR_Headers} DESTINATION ${Lib_IncludeDistribution_DIR}/)
# 


# message(STATUS ${DIR_Headers})
        


 