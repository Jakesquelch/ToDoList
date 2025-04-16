# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Output executable name
TARGET = a

# Source files
SRCS = main.cpp Task.cpp TodoList.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
