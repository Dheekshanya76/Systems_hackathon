CXX = clang++

CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -Iinclude

TARGET = chronicle

SRC = \
	src/main.cpp \
	src/command.cpp \
	src/executor.cpp \
	src/world_state.cpp \
	src/entity.cpp \
	src/pager.cpp
	
OBJ = $(SRC:.cpp=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)


src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)


rebuild: clean all


run: $(TARGET)
	./$(TARGET)


.PHONY: all clean rebuild run