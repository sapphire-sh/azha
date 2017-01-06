cmake_minimum_required(VERSION 3.2)
project(azha C CXX)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

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

find_package(BOOST)
if(BOOST_FOUND)
  list(APPEND AZHA_INC_DIRS ${BOOST_INCLUDE_DIR})
  list(APPEND AZHA_LIBS ${BOOST_LIBRARIES})
endif()

list(APPEND AZHA_SRCS
  ${INC_DIR}/azha.hpp
  ${SRC_DIR}/azha.cpp
  ${INC_DIR}/TwitterParameters.hpp
  ${SRC_DIR}/TwitterParameters.cpp
)

include_directories(${AZHA_INC_DIRS})

add_library(azha ${AZHA_SRCS})
target_link_libraries(azha ${AZHA_LIBS})
