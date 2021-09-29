cmake_minimum_required(VERSION 3.16)
Project(Server)

SET(SOCKETSRC SocktTest.cpp)

INCLUDE_DIRECTORIES(Common)
INCLUDE_DIRECTORIES(NetWork)

ADD_SUBDIRECTORY(NetWork)

ADD_EXECUTABLE(SockeTest ${SOCKETSRC})

TARGET_LINK_LIBRARIES(SockeTest ${PROJECT_SOURCE_DIR}/build/NetWork/libNetWork.so)

ADD_EXECUTABLE(reciver ReceTest.cpp)
TARGET_LINK_LIBRARIES(reciver ${PROJECT_SOURCE_DIR}/build/NetWork/libNetWork.so)

ADD_EXECUTABLE(sender SendTest.cpp)
TARGET_LINK_LIBRARIES(sender ${PROJECT_SOURCE_DIR}/build/NetWork/libNetWork.so)