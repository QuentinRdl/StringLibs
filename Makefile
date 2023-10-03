GTEST_ROOT = googletest/googletest

CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -pedantic -g -O2 -std=c99
# CFLAGS = -Wall -Wextra -pedantic -g -O2 -std=c99 -fsanitize=address
CXXFLAGS = -Wall -Wextra -pedantic -g -O2 -std=c++11 -I$(GTEST_ROOT)/include -I$(GTEST_ROOT)
LDLIBS = -lpthread
# LDFLAGS = -fsanitize=address

all: stringslib

stringslib: stringslib_test.o stringslib.o $(GTEST_ROOT)/src/gtest-all.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f stringslib_test.o stringslib.o $(GTEST_ROOT)/src/gtest-all.o
	rm -f stringslib
