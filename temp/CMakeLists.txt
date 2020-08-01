PROJECT(helloword) # 指定工程名称
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2) # 指定最小的版本
AUX_SOURCE_DIRECTORY(. DIR_SRCS) # 同步当前文件夹的所有文件到 DIR_SRCS 变量
# 找到动态库
include_directories(.)

Set(EXECUTABLE_NAME main.run)
ADD_EXECUTABLE(${EXECUTABLE_NAME} ${DIR_SRCS}) # 生成可执行文件,个人原因，喜欢在编译的可执行文件后面加上后缀
target_link_libraries(${EXECUTABLE_NAME})

# 复制
# copy out lib EXECUTABLE file...
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        copy "${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE_NAME}"
        "${EXECUTABLE_Distribution_DIR}/${EXECUTABLE_NAME}"
        #                   **** the following 2 lines are for potential future debug purpose ****
        #                   COMMAND "${CMAKE_COMMAND}" -E
        #                   remove_directory "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Copying ${PROJECT_NAME} to output directory")