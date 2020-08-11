PROJECT(zDemoExprAdvance) # 指定工程名称
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2) # 指定最小的版本
FILE (GLOB ALL_SOURCES "*.cpp" "*.c" "./AFolder/*.cpp" )
FILE (GLOB ALL_INCLUDES "*.hpp" "*.h" "./AFolder/*.hpp"  "./AFolder/*.h" )

SET (ALL_SRCS 
	 ${ALL_SOURCES}
	 ${ALL_INCLUDES}
)

SET(EXECUTABLE_NAME ExprAdvance.run)

ADD_EXECUTABLE(${EXECUTABLE_NAME} ${ALL_SRCS})
target_link_libraries(${EXECUTABLE_NAME} pthread lw_oopc)
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        copy "${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE_NAME}"
        "${EXECUTABLE_Distribution_DIR}/${EXECUTABLE_NAME}"
        #                   **** the following 2 lines are for potential future debug purpose ****
        #                   COMMAND "${CMAKE_COMMAND}" -E
        #                   remove_directory "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Copying ${EXECUTABLE_NAME} to output directory")
# 最后打印数据
message(STATUS "${PROJECT_NAME}::Compile complete.")
