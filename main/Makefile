CC = g++
CFLAGS = -c -Wall
BUILDDIR = ./build

# Get a list of all .cc files in the current directory
SOURCES = $(wildcard ./*.cc)

# Generate a list of corresponding .o files in the build directory
OBJECTSWITHTEST = $(patsubst ./%.cc,$(BUILDDIR)/%.o,$(SOURCES))
OBJECTS = $(filter-out %_unittest.o,$(OBJECTSWITHTEST)) # main.o and *.o without tests
OBJECTSTEST = $(filter-out %main.o,$(OBJECTSWITHTEST)) # files to test using gtest_main

all: main.exe tests.exe

# Rule to build the main of section 4.3
main.exe: $(OBJECTS)
	$(CC) $^ -o $@

# Rule to build the executable to test functions used in main sec 4.3
tests.exe: $(OBJECTSTEST)
	$(CC) $^ -o $@ -lgtest_main -lgtest -pthread


# Rule to build object files
$(BUILDDIR)/%.o: ./%.cc
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# Clean the build directory
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
