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

list(APPEND AZHA_SRCS
  ${INC_DIR}/azha.hpp
  ${SRC_DIR}/azha.cpp
  ${INC_DIR}/TwitterParameters.hpp
	${INC_DIR}/OAuth.hpp
	${SRC_DIR}/OAuth.cpp
	${INC_DIR}/base64.hpp
	${SRC_DIR}/base64.cpp
)

find_package(CURL)
if(CURL_FOUND)
  list(APPEND AZHA_INC_DIRS
		${CURL_INCLUDE_DIR}
	)
  list(APPEND AZHA_LIBS
		${CURL_LIBRARIES}
	)
endif()

find_package(OPENSSL)
if(OPENSSL_FOUND)
	list(APPEND AZHA_INC_DIRS
		${OPENSSL_INCLUDE_DIR}
	)
	list(APPEND AZHA_LIBS
		${OPENSSL_CRYPTO_LIBRARY}
	)
endif()

include_directories(${AZHA_INC_DIRS})

add_library(azha ${AZHA_SRCS})
target_link_libraries(azha ${AZHA_LIBS})

list(APPEND AZHA_CLI_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/cli/main.cpp
)

list(APPEND AZHA_CLI_LIBS
	azha
)

add_executable(azha_cli ${AZHA_CLI_SRCS})
target_link_libraries(azha_cli ${AZHA_CLI_LIBS})
