CXX = g++
CXX_FLAGS = -MMD -MP -Wall -Wextra
DIRS = bin build
SRCS = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp src/util/*.hpp)
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))
TARGET = bin/xvm
TARGET_TEST = bin/test
OBJS_TEST = $(patsubst src/test/%.cpp, build/test/%.o, $(wildcard src/test/*.cpp))
VERSION := $(shell git describe --tags --abbrev=0)
LATEST_COMMIT := $(shell git rev-parse --short HEAD)

all: version $(DIRS) $(TARGET)

version:
	@printf "# Writing version to src/version.hpp..."
	
	@echo   "#pragma once"                        > src/version.hpp
	@echo   ""                                   >> src/version.hpp
	@echo   "#ifndef xVM_VERSION"                >> src/version.hpp
	@echo   "#define xVM_VERSION \"$(VERSION)\"" >> src/version.hpp
	@echo   "#endif"                             >> src/version.hpp
	@echo   "#ifndef xVM_VERSION_ID"              >> src/version.hpp
	@echo   "#define xVM_VERSION_ID \"$(LATEST_COMMIT)\""  >> src/version.hpp
	@echo   "#endif"                             >> src/version.hpp
	
	@printf "done\n"

bin:
	@mkdir -pv bin

build:
	@mkdir -pv build

$(TARGET): $(OBJS)
	@printf "# Linking $@..."
	@$(CXX) $(CXX_FLAGS) $^ -o $(TARGET)
	@printf "done\n"

build/%.o: src/%.cpp
	@printf "# Compiling $<..."
	@$(CXX) $(CXX_FLAGS) -c $< -o $@
	@printf "done\n"

clean:
	@printf "# Removing bin..."
	@rm -rf bin
	@printf "done\n# Removing build..."
	@rm -rf build
	@printf "done\n"

.PHONY: clean dirs version
