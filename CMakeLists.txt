cmake_minimum_required(VERSION 3.17)

project(ProjectName)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(calculator Add.hpp Div.hpp Factory.hpp Mult.hpp Pow.hpp Sub.hpp base.hpp main.cpp op.hpp)
ADD_EXECUTABLE(test test.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

