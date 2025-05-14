CXX = g++
CXX_FLAGS = -MMD -MP -Wall -Wextra
DIRS = bin build
SRCS = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp src/util/*.hpp)
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))
TARGET = bin/xvm

all: $(DIRS) $(TARGET)

bin:
	@mkdir -v bin

build:
	@mkdir -v build

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

.PHONY: clean dirs
