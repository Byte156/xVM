VERSION_TYPE ?= build
SOURCES := $(wildcard src/**/*.cpp src/lib/**/*.cpp src/**/*.hpp src/lib/**/*.hpp)
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))
DEPENDS := $(OBJECTS:.o=.d)

all: bin/xvm

bin:
	@mkdir -p bin

lib:
	@mkdir -p lib

build:
	@mkdir -p build

log:
	@mkdir -p log

build/xvm.o: src/main.cpp | build
	@printf "# Compiling xvm.o..."
	@g++ -MMD -MP -c $< -o $@
	@printf "done\n"

build/libxvm.o: src/lib/libxvm.cpp src/lib/libxvm.hpp | build
	@printf "# Compiling libxvm.o..."
	@g++ -MMD -MP -c src/lib/libxvm.cpp -fPIC -o build/libxvm.o
	@printf "done\n"

bin/xvm: build/xvm.o lib/libxvm.so | log bin
	@printf "# Linking bin/xvm..."
	@g++ -MMD -MP build/xvm.o -o bin/xvm -Llib -lxvm
	@printf "done\n"

lib/libxvm.so: src/lib/libxvm.cpp build/libxvm.o build/libxvmins.o | lib
	@printf "# Linking lib/libxvm.so..."
	@g++ -MMD -MP -shared build/libxvm.o build/libxvmins.o -o lib/libxvm.so
	@printf "done\n"

build/libxvmins.o: src/lib/libxvmins.cpp | build
	@printf "# Compiling build/libxvmins.o..."
	@g++ -MMD -MP -fPIC -c $< -o $@
	@printf "done\n"

run: bin/xvm
	@LD_LIBRARY_PATH=$(HOME)/xVM/lib ./bin/xvm

devbuild: bin/xvm
	@printf "# Linking bin/xvm..."
	@g++ -MMD -MP build/xvm.o -o bin/xvm -Llib -lxvm
	@printf "done\n"
	@./util/version.sh $(VERSION_TYPE); \

clean:
	@printf "# Cleaning build files..."
	@rm build/*
	@printf "done\n# Cleaning shared objects..."
	@rm lib/*
	@printf "done\n# Cleaning binaries..."
	@rm bin/*
	@printf "done\n"

clean_logs:
	@printf "# Cleaning logs..."
	@rm log/*
	@printf "done\n"

.PHONY: clean clean_logs all run devbuild
