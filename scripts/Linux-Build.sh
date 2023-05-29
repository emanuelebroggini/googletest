export LD_LIBRARY_PATH="/usr/lib/x86_64-linux-gnu/" && cd googletest && cd samples && g++ -o sample1_unittest sample1_unittest.cc sample1.cc -lpthread -lgtest_main -lgtest


