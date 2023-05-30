CC = g++
CFLAGS = -c -Wall
BUILDDIR = ./build

# Get a list of all .cc files in the source directory
SOURCES = $(wildcard ./*.cc)

# Generate a list of corresponding .o files in the build directory
OBJECTSWITHTEST = $(patsubst ./%.cc,$(BUILDDIR)/%.o,$(SOURCES))

# Rule to build the executable to test all the sample functions
samples.exe: $(OBJECTSWITHTEST)
	$(CC) $^ -o $@ -lgtest -pthread


# Rule to build object files
$(BUILDDIR)/%.o: ./%.cc
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@


# Clean the build directory
clean:
	rm -rf $(BUILDDIR)

.PHONY: clean
