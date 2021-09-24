include_directories(${gtest_SOURCE_DIR}/include $gtest_SOURCE_DIR})
add_executable(RunTests MyTests.cpp)
target_link_libraries(RunTests GTest::gtest GTest::gtest_main)