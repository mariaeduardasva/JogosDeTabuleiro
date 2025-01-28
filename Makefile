#variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
LDFLAGS = 
SRC_DIR = src
LIB_DIR = lib
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests
TARGET = $(BIN_DIR)/main
TEST_TARGET = $(BIN_DIR)/tests

#busca de arquivos .cpp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES = $(wildcard $(LIB_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES) $(LIB_FILES)))
TEST_OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(TEST_FILES)))

#regras
all: $(TARGET)

#compila o executável principal
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

#compila arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#compila testes
tests: $(TEST_TARGET)

$(TEST_TARGET): $(OBJ_FILES) $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#limpa
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#limpa obj
clean-obj:
	rm -rf $(OBJ_DIR)

#help
help:
	@echo "comandos:"
	@echo "  make         - Compila o proj principal"
	@echo "  make tests   - Compila os testes"
	@echo "  make clean   - Remove todos os binários e obj"
	@echo "  make clean-obj - Remove apenas arquivos obj"

.PHONY: all clean clean-obj help tests


