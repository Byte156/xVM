VERSION_TYPE ?= build
SOURCES := $(wildcard src/**/*.cpp src/lib/**/*.cpp src/**/*.hpp src/lib/**/*.hpp)
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))

all: bin/xvm

clean:
	rm -f ./build/*

bin:
	@mkdir -p bin

lib:
	@mkdir -p lib

build:
	@mkdir -p build

log:
	@mkdir -p log

build/xvm.o: src/main.cpp
	@printf "# Compiling main.o..."
	@g++ -MMD -MP -c src/main.cpp -o build/xvm.o
	@printf "done\n"

build/libxvm.o: src/lib/libxvm.cpp src/lib/libxvm.hpp
	@printf "# Compiling libxvm.o..."
	@g++ -MMD -MP -c src/lib/libxvm.cpp -fPIC -o build/libxvm.o
	@printf "done\n"

bin/xvm: log bin build/xvm.o lib/libxvm.so
	@printf "# Linking bin/xvm..."
	@g++ -MMD -MP build/xvm.o -o bin/xvm -Llib -lxvm
	@printf "done\n"
	@./util/version.sh $(VERSION_TYPE); \

lib/libxvm.so: build/libxvm.o
	@printf "# Linking lib/libxvm.so..."
	@g++ -MMD -MP -shared build/libxvm.o -o lib/libxvm.so
	@printf "done\n"

run: bin/xvm
	@LD_LIBRARY_PATH=$(HOME)/xVM/lib ./bin/xvm
