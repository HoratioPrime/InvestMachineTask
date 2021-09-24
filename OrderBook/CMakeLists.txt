# CMakeList.txt : CMake project for OrderBook, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (OrderBook "OrderBook.cpp" "OrderBook.h")


add_subdirectory(lib/googletest)
add_subdirectory(tests)
