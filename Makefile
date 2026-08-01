CXX = clang++

CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -Iinclude

TARGET = chronicle

SRC = \
	src/main.cpp \
	src/command.cpp \
	src/world_state.cpp

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild run