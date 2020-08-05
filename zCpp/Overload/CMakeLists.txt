PROJECT(zCppOverload) # 指定工程名称
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2) # 指定最小的版本



#  ls1.c mycat.c
Set(__Exe_Pre Overload1)

# 开始遍历，生成对应的可执行文件
FOREACH(Exe_Pre ${__Exe_Pre})
  # message(STATUS ${Exe_Pre})
  FILE(GLOB ${Exe_Pre}_SRCS ${Exe_Pre}.cpp)
  SET(EXECUTABLE_NAME ${Exe_Pre}.run)
  ADD_EXECUTABLE(${EXECUTABLE_NAME} ${${Exe_Pre}_SRCS})
  target_link_libraries(${EXECUTABLE_NAME} pthread)    
  add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        copy "${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE_NAME}"
        "${EXECUTABLE_Distribution_DIR}/${EXECUTABLE_NAME}"
        #                   **** the following 2 lines are for potential future debug purpose ****
        #                   COMMAND "${CMAKE_COMMAND}" -E
        #                   remove_directory "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Copying ${EXECUTABLE_NAME} to output directory")
ENDFOREACH(Exe_Pre)

# 最后打印数据
message(STATUS "${PROJECT_NAME}::Compile complete.")
