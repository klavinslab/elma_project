#Architecture
ARCH := $(shell uname -m)

#Compilers
CC          := g++ -std=c++14 -Wno-psabi
DGEN        := doxygen

#The Target Binary Program
TARGET      := stopwatch

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./src
INCDIR      := ./include
BUILDDIR    := ./build
TARGETDIR   := ./bin
SRCEXT      := cc

#Flags, Libraries and Includes
CFLAGS      := 
LIB         := -L../lib -lgtest -lpthread -lelma -lssl -lcrypto -lcurses
INC         := -I$(INCDIR)
INCDEP      := -I$(INCDIR)

#Files
HEADERS     := $(wildcard ./include/*.h)
SOURCES     := $(wildcard ./src/*.cc)
OBJECTS     := $(patsubst %.cc, $(BUILDDIR)/%.o, $(notdir $(SOURCES)))
NON_MAIN_OBJECTS     := $(filter-out ./build/main.o,$(OBJECTS))
DGENCONFIG  := docs.config

#Defauilt Make
all: directories $(TARGETDIR)/$(TARGET) bin/test

docs: docs/index.html

docs/index.html: $(SOURCES) $(HEADERS) README.md docs.config 
	$(DGEN) $(DGENCONFIG)
	cp .nojekyll docs

#Remake
remake: spotless all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)/*.o *.o bin/*

#Full Clean, Objects and Binaries
spotless: clean
	@$(RM) -rf $(TARGETDIR)/$(TARGET) *.db
	@$(RM) -rf build bin html latex

#Unit Tester
bin/test: $(NON_MAIN_OBJECTS) $(HEADERS) ./src/unit_test.cc ./src/test_main.cpp
	$(CC) $(CFLAGS) $(INC) -c -o test_main.o ./src/test_main.cpp
	$(CC) $(CFLAGS) -o bin/test test_main.o $(NON_MAIN_OBJECTS) $(LIB)

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGETDIR)/$(TARGET) $(OBJECTS) $(LIB)

#Compile
$(BUILDDIR)/%.o: $(SRCDIR)/%.cc $(HEADERS) 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: directories remake clean cleaner apidocs $(BUILDDIR) $(TARGETDIR)
