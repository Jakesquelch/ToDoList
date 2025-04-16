# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I../include

# Output executable name
TARGET = a

# Source files
SRCS = main.cpp Task.cpp ToDoList.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
