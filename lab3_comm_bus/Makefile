CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinc -g -fsanitize=address,undefined

SRCS   := main.cpp $(wildcard src/*.cpp)
TARGET := main

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean