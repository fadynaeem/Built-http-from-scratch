cmake_minimum_required(VERSION 3.16)

project(BuiltHttpFromScratch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(built_http_server
    src/JSON.cpp
    src/main.cpp
    src/Middlewares.cpp
    src/Parser.cpp
    src/Request.cpp
    src/Response.cpp
    src/Router.cpp
    src/ServerHandling.cpp
    src/SetNetwork.cpp
    src/ThreadPool.cpp
    src/core/app.cpp
)

target_include_directories(built_http_server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(built_http_server PRIVATE Threads::Threads)

if(WIN32)
    target_link_libraries(built_http_server PRIVATE ws2_32)
endif()
