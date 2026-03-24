# JujutsuLang — Makefile
# Phase 2: Flex + Bison (Lexer + Parser)

LEX      = flex
BISON    = bison
CXX      = g++
CXXFLAGS = -Wall -Wno-deprecated -x c++
TARGET   = jujutsu
LEXSRC   = jujutsu.l
PARSRC   = jujutsu.y
LEXOUT   = lex.yy.c
PAROUT   = jujutsu.tab.c
PARHDR   = jujutsu.tab.h

# ---- Compile Modes ----
# Use 'make lexer' for Phase 1 (Flex only)
# Use 'make parser' or 'make all' for Phase 2 (Flex + Bison)

.PHONY: all lexer parser clean test help

help:
	@echo "JujutsuLang Compiler Build Targets:"
	@echo "  make lexer   - Build Phase 1 (Flex lexer only)"
	@echo "  make parser  - Build Phase 2 (Flex + Bison parser)"
	@echo "  make all     - Build Phase 2 (default)"
	@echo "  make test    - Run tests"
	@echo "  make clean   - Clean build artifacts"

all: parser

# ---- PHASE 1: LEXER ONLY ----
lexer: $(LEXOUT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(LEXOUT) -lfl
	@echo "Built Phase 1 (Lexer): $(TARGET)"

# ---- PHASE 2: LEXER + PARSER ----
parser: $(PAROUT) $(LEXOUT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(PAROUT) $(LEXOUT) -lfl
	@echo "Built Phase 2 (Parser): $(TARGET)"

# ---- BUILD STEPS ----

# Bison parser: jujutsu.y → jujutsu.tab.c
$(PAROUT) $(PARHDR): $(PARSRC)
	$(BISON) -d $(PARSRC)

# Flex lexer: jujutsu.l → lex.yy.c
$(LEXOUT): $(LEXSRC)
	$(LEX) -o $(LEXOUT) $(LEXSRC)

# ---- TESTING ----
test: parser
	./$(TARGET) input.jjk
	@echo "Test complete."

# ---- CLEANUP ----
clean:
	rm -f $(LEXOUT) $(PAROUT) $(PARHDR) $(TARGET) output.tok
	@echo "Cleaned."
