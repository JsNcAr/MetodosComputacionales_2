# Nombre del ejecutable
EXECUTABLE = output

# Carpetas
SRC_DIR = src
BUILD_DIR = build

# Archivos fuente y objetos
# Use the wildcard function to collect a list of .cpp files matching the pattern in the SRC_DIR directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Use the patsubst function to transform each .cpp file path into a corresponding .o file path in the BUILD_DIR directory
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Compilador y opciones
CC = g++
CFLAGS = -std=c++14 -Wall -Wextra -pedantic

# Reglas
# The 'all' target: Create the BUILD_DIR and the EXECUTABLE
all: $(BUILD_DIR) $(EXECUTABLE)

# Rule to create the BUILD_DIR
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to create the EXECUTABLE by compiling the OBJECTS
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Rule to compile each .cpp source file into a .o object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# The 'clean' target: Remove the BUILD_DIR and the EXECUTABLE
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
