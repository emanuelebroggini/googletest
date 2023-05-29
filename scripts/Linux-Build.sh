#!/bin/bash
cd googletest && cd samples && g++ -o tests sample1_unittest.cc sample1.cc sample2_unittest.cc sample2.cc -lpthread -lgtest_main -lgtest


