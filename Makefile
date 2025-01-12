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
	@if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	@if exist $(BINDIR) rmdir /s /q $(BINDIR)

# Regras especiais
.PHONY: all clean
