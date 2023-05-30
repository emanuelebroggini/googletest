CC = g++
CFLAGS = -c -Wall
SRCDIR = ../googletest/samples
BUILDDIR = ../build
MAINDIR = ../main

# Get a list of all .cc files in the source directory
SOURCES = $(wildcard $(SRCDIR)/*.cc)

# Generate a list of corresponding .o files in the build directory
OBJECTSWITHTEST = $(patsubst $(SRCDIR)/%.cc,$(BUILDDIR)/%.o,$(SOURCES))
OBJECTS = $(filter-out %_unittest.o,$(OBJECTSWITHTEST))

all: tests

# Rule to build the main of section 4.3
main: $(OBJECTS) $(MAINDIR)/build/main.o
	$(CC) $^ -o $@

# Rule to build the executable to test all the sample functions
tests: $(OBJECTSWITHTEST)
	$(CC) $^ -o $@ -lgtest_main -lgtest -pthread


# Rule to build object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# Rule to build object file of main section 4.3
$(MAINDIR)/build/main.o: $(MAINDIR)/main.cc
	@mkdir -p $(MAINDIR)/build
	$(CC) $(CFLAGS) $< -o $@


# Clean the build directory
clean:
	rm -rf $(BUILDDIR)
	rm -rf $(MAINDIR)/build/

.PHONY: clean
