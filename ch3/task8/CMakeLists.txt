cmake_minimum_required( VERSION 2.8 )
project( trajectoryErrorRMSE )
set(CMAKE_BUILD_TYPE "Release")
set(EXECUTABLE_OUTPUT_PATH bin)
message(STATUS "EXECUTABLE file path:" ${PROJECT_BINARY_DIR}/build/${EXECUTABLE_OUTPUT_PATH})

# 为使用 sophus，您需要使用find_package命令找到它
find_package( Sophus REQUIRED )
find_package(Pangolin REQUIRED)
include_directories(
        ${Sophus_INCLUDE_DIRS}
        ${Pangolin_INCLUDE_DIRS})

add_executable( trajectoryErrorRMSE trajectory_error.cpp )
target_link_libraries(trajectoryErrorRMSE
        ${Sophus_LIBRARIES}
        ${Pangolin_LIBRARIES}
        ${FMT_LIBRARIES})