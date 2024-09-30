all: bin/xvm.exe

bin:
	@mkdir -p bin

bin/xvm.exe: bin bin/xvm.o
	@printf "Compiling bin/xvm.exe..."
	@g++ bin/xvm.o -o bin/xvm.exe
	@g++ bin/xvm.o -o bin/xvm
	@printf "done\n"

bin/xvm.o: bin src/main.cpp
	@printf "Compiling bin/xvm.o..."
	@g++ -c src/main.cpp -o bin/xvm.o
	@printf "done\n"
