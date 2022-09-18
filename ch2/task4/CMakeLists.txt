CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( task4 )

SET( CMAKE_BUILD_TYPE "Release" )
SET( CMAKE_CXX_FLAGS "-O3" )

# 添加Eigen头文件
INCLUDE_DIRECTORIES( "/usr/include/eigen3" )

# in osx and brew install
# include_directories( /usr/local/Cellar/eigen/3.3.3/include/eigen3 )

ADD_EXECUTABLE( coordinateTransformation coordinateTransformation.cpp )