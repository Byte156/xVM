VERSION_TYPE ?= build

all: bin/xvm

bin:
	@mkdir -p bin

lib:
	@mkdir -p lib

build:
	@mkdir -p build

bin/xvm: bin build/xvm.o lib/libxvm.so
	@printf "# Compiling bin/xvm..."
	@g++ build/xvm.o -o bin/xvm -L lib -lxvm
	@printf "done\n"
	@./util/version.sh $(VERSION_TYPE)

build/xvm.o: build src/main.cpp
	@printf "# Compiling bin/xvm.o..."
	@g++ -c src/main.cpp -o build/xvm.o
	@printf "done\n"

build/libxvm.o: build src/lib/libxvm.cpp
	@printf "# Compiling build/libxvm.o..."
	@g++ -c src/lib/libxvm.cpp -fPIC -o build/libxvm.o
	@printf "done\n"

lib/libxvm.so: lib build/libxvm.o
	@printf "# Compiling lib/libxvm.so..."
	@g++ -shared build/libxvm.o -o lib/libxvm.so
	@printf "done\n"

run: bin/xvm
	@LD_LIBRARY_PATH=/home/user/xVM/lib ./bin/xvm