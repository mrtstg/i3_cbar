BUILD_FILES=main.cpp libs/*.cpp
CFLAGS=-lstdc++ -std=c++11 -O1 -o target/bin

all: run

build: target/ $(BUILD_FILES)
	clang $(BUILD_FILES) $(CFLAGS)

target/:
	mkdir target

run: build
	./target/bin

libs:
	mkdir libs
	wget https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp -O libs/json.hpp
