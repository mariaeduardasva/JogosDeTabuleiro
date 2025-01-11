# Variáveis
CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/programa

# Arquivos fonte e objetos
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

# Regras
all: $(TARGET)

$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Regras especiais
.PHONY: all clean
