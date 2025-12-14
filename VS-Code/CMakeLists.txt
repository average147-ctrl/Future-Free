cmake_minimum_required(VERSION 3.10)
project(my_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(my_app ${SOURCES} ${HEADERS})

target_include_directories(my_app PRIVATE
    include
    "C:/msys64/mingw64/include"
)

target_link_directories(my_app PRIVATE
    "C:/msys64/mingw64/lib"
)

target_link_libraries(my_app PRIVATE pqxx pq)