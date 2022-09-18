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

# 安装之后来运行这个
# 用findxxx.cmake查找
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/findcmake)
find_package(Hello REQUIRED)
include_directories(${HELLO_INCLUDE_DIR})

# 生成可执行文件
add_executable(run_hello useHello.cpp)
target_link_libraries(run_hello ${HELLO_LIBRARY})
