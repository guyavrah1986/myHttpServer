# CMakeLists.txt file for the cpp11ThreadWrapper library
# ======================================================
set(libName "infraLib")

add_library(${libName} cpp11ThreadWrapper.cpp)

# In order to use the C++11 <thread> one needs to link against
# the respective "system threading library". The project intendent
# to run on Linux machine, so link to pthread.
target_link_libraries(${libName} pthread)

target_compile_options(${libName} PUBLIC -g -O0 -Wall -fprofile-arcs -ftest-coverage)
target_link_options(${libName} PUBLIC -fprofile-arcs -ftest-coverage)

message(STATUS "CMakeLists.txt of ${libName} - created library")