#variáveis
CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
SRCDIR = src
LIBDIR = lib
TESTDIR = tests
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/programa
TESTBIN = $(BINDIR)/testes

#arquivos fonte e objetos
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
LIBFILES = $(wildcard $(LIBDIR)/*.cpp)
TESTFILES = $(wildcard $(TESTDIR)/*.cpp)
ALLFILES = $(SRCFILES) $(LIBFILES)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES)) \
           $(patsubst $(LIBDIR)/%.cpp,$(OBJDIR)/%.o,$(LIBFILES))
TESTOBJFILES = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTFILES))

#regras principais
all: $(TARGET)

$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(LIBDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#regras para testes
tests: $(TESTBIN)
	@./$(TESTBIN)

$(TESTBIN): $(OBJFILES) $(TESTOBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(BINDIR)
#regras especiais
.PHONY: all clean tests

