#!/bin/bash
cd /var/lib/jenkins/workspace/googletest_main/googletest/samples
g++ -o sample1_unittest sample1_unittest.cc sample1.cc -lgtest -lpthread
