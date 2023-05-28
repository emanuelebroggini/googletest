#!/bin/bash
cd googletest && cd samples && g++ -o sample1_unittest sample1_unittest.cc sample1.cc -lgtest -lpthread
