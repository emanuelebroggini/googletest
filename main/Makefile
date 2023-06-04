CC = g++
CFLAGS = -c -Wall
BUILDDIR = ./build
SAMPLEDIR = ../googletest/samples
BUILDSAMPLEDIR = $(SAMPLEDIR)/build

all: main.exe

# Rule to build the main of section 4.3
main.exe: $(BUILDDIR)/main.o $(BUILDSAMPLEDIR)/sample1.o
	$(CC) $^ -o $@

# Rule to build main object file
$(BUILDDIR)/%.o: ./%.cc
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# Rule to build sample object files (Here I only need sample1)
$(BUILDSAMPLEDIR)/%.o: $(SAMPLEDIR)/%.cc
	@mkdir -p $(BUILDSAMPLEDIR)
	$(CC) $(CFLAGS) $< -o $@

# Clean the build directory
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
