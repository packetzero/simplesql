CMAKE_MINIMUM_REQUIRED(VERSION 2.7)

set (PROJECT_NAME simplesql-tests)
PROJECT(${PROJECT_NAME})

file(GLOB HDRS "../*.h*" )
file(GLOB SRCS "*.cpp")

include_directories(.. ${GTEST_DIR}/include )


add_executable (${PROJECT_NAME} ${SRCS} ${HDRS})

FIND_LIBRARY(ANTLR_LIB antlr4-runtime HINT /usr/local/lib )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} simplesql ${GTEST_DIR}/lib/libgtest.a ${ANTLR_LIB})
