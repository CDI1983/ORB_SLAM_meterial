# message level: STATUS = 非重要信息
#                WARNING = 警告，会继续执行
#                AUTHOR_WARNING = 警告，会继续执行
#                SEND_ERROR = 错误，继续执行，但是会跳过生成的步骤
#                FATAL_ERROR = 错误，终止所有处理过程
message(STATUS "Hello CMake!")
# cmake 版本
cmake_minimum_required(VERSION 3.0)
# 定义项目名字
project(cmake_practice)
# 定义编译模式
set(CMAKE_BUILD_TYPE "Release")
# 定义可执行文件输出路径 and 打印输出路径
set(EXECUTABLE_OUTPUT_PATH bin)
message(STATUS "EXECUTABLE file path:" ${PROJECT_BINARY_DIR}/build/${EXECUTABLE_OUTPUT_PATH})

# 加载库函数生成share库
add_library(hello SHARE ${PROJECT_SOURCE_DIR}/src/hello.cpp)
# 引入头文件
target_include_directories(hello PRIVATE ${PROJECT_SOURCE_DIR}/include)
set_target_properties(hello PROPERTIES PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/hello.h)

# 生成可执行文件
add_executable(run_hello useHello.cpp)
# 对应连接.so和.h文件
target_link_libraries(run_hello hello)
target_include_directories(run_hello PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 将库文件，头文件安装到指定目录
install(TARGETS hello
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

