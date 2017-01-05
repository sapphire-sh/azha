cmake_minimum_required(VERSION 3.2)
project(azha C CXX)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EXT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AZHA_INC_DIRS
  ${INC_DIR}
  ${SRC_DIR}
)

find_package(CURL)
if(CURL_FOUND)
  list(APPEND AZHA_INC_DIRS ${CURL_INCLUDE_DIR})
  list(APPEND AZHA_LIBS ${CURL_LIBRARIES})
endif()

list(APPEND AZHA_SRCS
  ${SRC_DIR}/azha.cpp
)

add_library(azha ${AZHA_SRCS})
target_link_libraries(azha ${AZHA_LIBS})
