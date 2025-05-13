cmake_minimum_required(VERSION 3.10)
project(linalg VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DLINALG_EXPORTS)

set(SOURCES
    src/gauss.cpp
    src/jacobi.cpp
    src/linalg_error.cpp    
    src/matrix.cpp
    src/matrix_generator.cpp
    src/sle_generator.cpp
    src/utils.cpp
    src/vector.cpp
    src/vector_generator.cpp
    src/wrapper.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    )
    
    set_target_properties(${PROJECT_NAME} PROPERTIES
        PREFIX ""
    )
endif()