# Nombre del ejecutable
TARGET = build/simulacion.o

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I src

# Dependencias de SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Directorios
SRC_DIR = src
BUILD_DIR = build

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Reglas
all: run

run: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

runAll: run
	./$(BUILD_DIR)/simulacion.o

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all run runAll clean
