cmake_minimum_required(VERSION 3.2)
project(azha C CXX)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(AZHA_INC_DIRS
	${INC_DIR}
	${SRC_DIR}
)

list(APPEND AZHA_SRCS
	${INC_DIR}/azha.hpp
	${INC_DIR}/client.hpp
	${SRC_DIR}/client.cpp
	${INC_DIR}/oauth.hpp
	${SRC_DIR}/oauth.cpp
	${INC_DIR}/parameters.hpp
	${INC_DIR}/parameters.interface.hpp
	${INC_DIR}/parameters.oauth.hpp
	${INC_DIR}/parameters.account.hpp
	${INC_DIR}/parameters.application.hpp
	${INC_DIR}/parameters.blocks.hpp
	${INC_DIR}/parameters.collections.hpp
	${INC_DIR}/parameters.direct_messages.hpp
	${INC_DIR}/parameters.favorites.hpp
	${INC_DIR}/parameters.followers.hpp
	${INC_DIR}/parameters.friends.hpp
	${INC_DIR}/parameters.friendships.hpp
	${INC_DIR}/parameters.geo.hpp
	${INC_DIR}/parameters.help.hpp
	${INC_DIR}/parameters.lists.hpp
	${INC_DIR}/parameters.media.hpp
	${INC_DIR}/parameters.mutes.hpp
	${INC_DIR}/parameters.projects.hpp
	${INC_DIR}/parameters.saved_searches.hpp
	${INC_DIR}/parameters.search.hpp
	${INC_DIR}/parameters.statuses.hpp
	${INC_DIR}/parameters.trends.hpp
	${INC_DIR}/parameters.users.hpp
	${INC_DIR}/base64.hpp
	${SRC_DIR}/base64.cpp
)

find_package(CURL REQUIRED)
if(CURL_FOUND)
	list(APPEND AZHA_INC_DIRS
		${CURL_INCLUDE_DIR}
	)
	list(APPEND AZHA_LIBS
		${CURL_LIBRARIES}
	)
endif()

find_package(OPENSSL REQUIRED)
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
target_compile_features(azha PUBLIC cxx_auto_type cxx_range_for cxx_nullptr)

list(APPEND AZHA_CLI_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/cli/main.cpp
)

list(APPEND AZHA_CLI_LIBS
	azha
)

add_executable(azha_cli ${AZHA_CLI_SRCS})
target_link_libraries(azha_cli ${AZHA_CLI_LIBS})
