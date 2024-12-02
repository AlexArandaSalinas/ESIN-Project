# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -ansi -g

# Target executable
TARGET = driver_joc_par

# Source files
SRCS = driver_joc_par.cpp \
       obte_paraules.cpp \
       anagrames.cpp \
       iter_subset.cpp \
       diccionari.cpp \
       word_toolkit.cpp

# Header files
HEADERS = obte_paraules.h \
          anagrames.h \
          iter_subset.h \
          diccionari.h \
          word_toolkit.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
