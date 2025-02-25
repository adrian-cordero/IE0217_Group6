# Nombre del ejecutable
TARGET = build/simulacion

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I src  -MMD -MP

# Dependencias de SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Directorios
SRC_DIR = src
BUILD_DIR = build

# Dependency files (auto-generated)
DEPS = $(OBJS:.o=.d)

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

run: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Compilation step for each .cpp file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include auto-generated dependency files
-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)