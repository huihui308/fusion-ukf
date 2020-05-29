cmake_minimum_required(VERSION 3.5)
set( prjName UnscentedKF )

add_definitions(-std=c++0x)


###### change the default location of executables
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


include_directories(headers)

set(SOURCES src/tools.cpp
            src/usagecheck.cpp
            src/measurementpredictor.cpp
            src/statepredictor.cpp
            src/stateupdater.cpp
            src/datapoint.cpp
            src/fusionukf.cpp
            src/main.cpp)

add_executable(${prjName} ${SOURCES})
