CMAKE_MINIMUM_REQUIRED(VERSION 2.7)

set (PROJECT_NAME simplesql)
PROJECT(${PROJECT_NAME})

file(GLOB HDRS "../gencpp/*.h*" "*.h*")
file(GLOB SRCS "../gencpp/*.cpp" "*.cpp" )

include_directories(../gencpp  )

add_library (${PROJECT_NAME} ${SRCS} ${HDRS})

install(TARGETS simplesql ARCHIVE DESTINATION lib)
