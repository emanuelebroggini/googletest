CC = g++
CFLAGS = -c -Wall
BUILDDIR = ./build

# Get a list of all .cc files in the source directory
SOURCES = $(wildcard ./*.cc)

# Generate a list of corresponding .o files in the build directory
OBJECTSWITHTEST = $(patsubst ./%.cc,$(BUILDDIR)/%.o,$(SOURCES))

all: samples135.exe samples678.exe sample2.exe sample4.exe sample9.exe sample10.exe


# Rule to build the executable to test all the sample functions
samples135.exe: $(BUILDDIR)/sample1.o $(BUILDDIR)/sample1_unittest.o $(BUILDDIR)/sample3_unittest.o $(BUILDDIR)/sample5_unittest.o
	$(CC) $^ -o $@ -lgtest -pthread -lgtest_main

samples678.exe: $(BUILDDIR)/sample6_unittest.o $(BUILDDIR)/sample7_unittest.o $(BUILDDIR)/sample8_unittest.o # $(BUILDDIR)/prime_tables.o
	$(CC) $^ -o $@ -lgtest -pthread -lgtest_main

sample2.exe: $(BUILDDIR)/sample2.o $(BUILDDIR)/sample2_unittest.o
	$(CC) $^ -o $@ -lgtest -pthread -lgtest_main

sample4.exe: $(BUILDDIR)/sample4.o $(BUILDDIR)/sample4_unittest.o
	$(CC) $^ -o $@ -lgtest -pthread -lgtest_main
	

sample9.exe: $(BUILDDIR)/sample9_unittest.o
	$(CC) $^ -o $@ -lgtest -pthread

sample10.exe: $(BUILDDIR)/sample10_unittest.o
	$(CC) $^ -o $@ -lgtest -pthread
	

# Rule to build object files
$(BUILDDIR)/%.o: ./%.cc
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@


# Clean the build directory
clean:
	rm -rf $(BUILDDIR)

.PHONY: clean all
