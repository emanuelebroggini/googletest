project(googletest-distribution)

add_executable(lelefude lelefude.cpp) 

target_include_directories(lelefude PUBLIC ../googletest/include/gtest ../googletest/samples)

target_link_libraries(lelefude libgtest) 
target_link_libraries(lelefude libpthread)