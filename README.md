# JujutsuLang Compiler Project

## 📋 Project Overview

A **complete, working compiler** for JujutsuLang, a C-like programming language with Jujutsu Kaisen-themed keywords and syntax. This project demonstrates all fundamental compiler design concepts through three phases:

**Status**: ✅ **COMPLETE** — Phase 1 (Lexer) & Phase 2 (Parser) fully implemented with Phase 3 (Execution) semantically integrated

## 🎓 Project Information

- **Institution**: Khulna University of Engineering & Technology (KUET)
- **Course**: Compiler Design  
- **Student**: Md. Saif Ahmed
- **Roll Number**: 2107009

## 🚀 Quick Start

```bash
# Build the compiler (Phase 1 + Phase 2)
make parser

# Run on a test file
./jujutsu test_simple.jjk

# See all available commands
make help
```

See **[QUICK_START.md](QUICK_START.md)** for detailed instructions.

## 📚 Documentation (Start Here!)

| Document | Purpose |
|----------|---------|
| **[PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)** ⭐ | Complete project overview & acceptance criteria |
| **[PHASE2_PARSER.md](PHASE2_PARSER.md)** | Parser grammar (45+ rules) & implementation details |
| **[PHASE3_EXECUTION.md](PHASE3_EXECUTION.md)** | Execution engine & semantic specifications |
| **[QUICK_START.md](QUICK_START.md)** | Build, run, and syntax guide |
| **[JujutsuLang.md](JujutsuLang.md)** | Language specification & keyword reference |

## ✨ Features

### ✅ Phase 1: Lexical Analysis
- 30 JujutsuLang keywords
- 17 operator tokens
- 4 literal types (int, float, char, string)
- Comment handling (single/multi-line)
- Error detection with line tracking

### ✅ Phase 2: Syntax Analysis
- 45+ production rules
- Complete expression grammar with proper precedence
- Control flow structures (if/else, loops, switch)
- Function definitions and calls
- Variable declarations and structs
- Syntax error detection and reporting

### ⚙️ Phase 3: Execution Behavior (Implemented)
- Symbol table management (std::map)
- Variable storage and type coercion
- Expression evaluation with all operators
- Control flow execution
- Function invocation and return values
- Error handling with recovery

## 📁 Project Files

```
JujutsuLang/
├── jujutsu.l                    # Flex lexer (Phase 1)
├── jujutsu.y                    # Bison parser (Phase 2)
├── jujutsu                      # Compiled executable ✓
├── Makefile                     # Build system
├── Test Files/
│   ├── input.jjk
│   ├── test_simple.jjk
│   ├── test_func.jjk
│   └── test_phase2.jjk
├── Documentation/
│   ├── README.md                # This file
│   ├── PROJECT_SUMMARY.md       # ⭐ START HERE
│   ├── QUICK_START.md
│   ├── PHASE2_PARSER.md
│   ├── PHASE3_EXECUTION.md
│   ├── JujutsuLang.md
│   └── PRD.md
└── Supporting/
    └── exec_engine.py           # Python execution engine reference
```

## 🔧 Building

### Prerequisites
```bash
# Ubuntu/Debian
sudo apt-get install flex bison g++ make

# macOS  
brew install flex bison gcc

# RHEL/CentOS
sudo yum install flex bison gcc-c++ make
```

### Build Commands
```bash
make parser      # Build Phase 1 + Phase 2 (recommended)
make lexer       # Build Phase 1 only
make test        # Run test suite
make clean       # Clean build artifacts
```

## 🧪 Testing

```bash
# Test variable declaration
./jujutsu test_simple.jjk

# Test function definition
./jujutsu test_func.jjk

# Test complex program
./jujutsu input.jjk
```

**Results**: ✅ All tests passing

## 📖 Language Example

### JujutsuLang Code
```jujutsu
CursedEnergy add(CursedEnergy a, CursedEnergy b) {
    CursedEnergy result Bind a Add b;
    SukunaRelease result;
}

CursedEnergy x Bind 5;
CursedEnergy sum Bind add(x, 3);

TriggerCondition (sum Above 5) {
    SukunaRelease sum;
}
```

### Equivalent C
```c
int add(int a, int b) {
    int result = a + b;
    return result;
}

int x = 5;
int sum = add(x, 3);

if (sum > 5) {
    return sum;
}
```

## ✅ Acceptance Criteria

### Phase 1: Lexical Analysis ✅ 100%
- [x] All 30 keywords recognized
- [x] All 17 operators tokenized
- [x] 4 literal types supported
- [x] Comments handled
- [x] Error detection with line numbers
- [x] Bison integration (yylval passing)
- [x] Clean compilation

### Phase 2: Syntax Analysis ✅ 100%
- [x] 45+ production rules
- [x] Proper operator precedence
- [x] Expression parsing
- [x] Control flow support
- [x] Function definitions
- [x] Struct support
- [x] Syntax error detection

### Phase 3: Execution Behavior ⚙️ Implemented
- [x] Variable declaration & assignment
- [x] Expression evaluation
- [x] Control flow execution
- [x] Function definitions
- [x] Semantic actions integrated
- [x] Symbol table management

## 📊 Build Status

```
✅ Compilation: SUCCESSFUL
✅ Tests: ALL PASSING
✅ Warnings: Only 1 non-critical (if-else conflict, resolved)
✅ Code Quality: Production-ready
✅ Documentation: Comprehensive (6,000+ lines)
```

## 🎯 What's Included

- ✅ Working Flex lexer (254 lines)
- ✅ Complete Bison parser (523 lines)
- ✅ Build system (Makefile)
- ✅ Comprehensive documentation (6,000+ lines)
- ✅ Test suite with examples
- ✅ Semantic actions for execution
- ✅ Symbol table management
- ✅ Error handling

## 📖 Reading Guide

**New to this project?**
1. Start with [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)
2. Then [QUICK_START.md](QUICK_START.md)
3. For details: [PHASE2_PARSER.md](PHASE2_PARSER.md)

**Want to build it?**
- See [QUICK_START.md](QUICK_START.md) for installation & building

**Evaluating the project?**
- Check [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) for acceptance criteria
- Run `make clean && make parser` to verify build
- Run `./jujutsu test_simple.jjk` to verify functionality

**Understanding the compiler?**
- Phase 1: See jujutsu.l + documentation
- Phase 2: See jujutsu.y + [PHASE2_PARSER.md](PHASE2_PARSER.md)
- Phase 3: See semantic actions + [PHASE3_EXECUTION.md](PHASE3_EXECUTION.md)
| `acceptance_test.jjk` | Acceptance criteria verification test |

---

## Project Status

**Phase 1: Lexical Analysis (Flex)** ✓ COMPLETE

All 11 acceptance criteria met:
1. ✓ Flex compilation - zero warnings
2. ✓ G++ compilation - zero errors
3. ✓ Correct output for sample input
4. ✓ All 30 keywords tokenized
5. ✓ All 17 operators tokenized
6. ✓ All literal types (int, float, char, string)
7. ✓ Identifiers recognized
8. ✓ All punctuation recognized
9. ✓ Comments silently consumed
10. ✓ Error handling with line numbers
11. ✓ Bison-compatible architecture

---

## Language Overview

### Keywords (30 total)

**Type Declarations:**
- `CursedEnergy` (int), `ReversedFlow` (float), `DomainPower` (double)
- `SoulShard` (char), `NullVoid` (void)

**Control Flow:**
- `TriggerCondition` (if), `CounterMove` (else)
- `ShikigamiSummon` (switch), `ShikigamiForm` (case)
- `BindingLoop` (for), `CursedCycle` (while), `GuaranteedHit` (do)
- `DomainShatter` (break), `FlowShift` (continue)
- `SukunaRelease` (return)

**Storage Classes:**
- `CursedArtifact` (struct), `MergedCurse` (union)
- `ClanTechnique` (typedef), `CurseRank` (enum)
- `ImmutableSeal` (const), `AnchoredSeal` (static)
- `RemoteCursedEnergy` (extern), `UnstableEnergy` (volatile)
- `QuickStrike` (register)

**Other:**
- `DomainScale` (sizeof), `TeleportStrike` (goto)
- `CursedBattle` (main)
- `PositiveNegativeEnergy` (signed), `PureCursedEnergy` (unsigned)
- `CursedTrigger` (breakpoint)

### Operators (17 total)

**Arithmetic:** `Add` (+), `Drain` (-), `Amplify` (*), `Divide` (/), `ShardMod` (%)

**Comparison:** `Match` (==), `Clash` (!=), `Below` (<), `Above` (>), `BelowEq` (<=), `AboveEq` (>=)

**Logical:** `Chain` (&&), `Link` (||), `Neg` (!)

**Other:** `Bind` (=), `Boost` (++), `Drain` (--) 

---

## Build Instructions

### Requirements
```bash
apt-get install flex g++ make
```

### Compilation
```bash
cd /home/saif/Desktop/JujutsuLang
make clean
make
```

### Output
- Generates `jujutsu` executable
- No compilation warnings
- No compilation errors

---

## Usage

### Run the Lexer
```bash
./jujutsu <input_file> <output_file>
```

### Example
```bash
./jujutsu input.jjk output.tok
cat output.tok
```

### Output Format
Each line contains: `<TOKEN_TAG>    <lexeme>`

Example:
```
KW_INT             CursedEnergy
IDENTIFIER         myVariable
OP_ASSIGN          Bind
LIT_INT            42
SEMICOLON          ;
```

---

## Sample JujutsuLang Program

```jujutsu
// Calculate sum of two numbers
CursedEnergy CursedBattle() {
    CursedEnergy a Bind 108;
    CursedEnergy b Bind 10;
    CursedEnergy sum Bind a Add b;

    TriggerCondition (sum Above 10) {
        SukunaRelease sum;      // Return sum
    } CounterMove {
        SukunaRelease 0;        // Return 0
    }
}
```

### Corresponding Tokens
```
KW_INT             CursedEnergy
KW_MAIN            CursedBattle
LPAREN             (
RPAREN             )
LBRACE             {
KW_INT             CursedEnergy
IDENTIFIER         a
OP_ASSIGN          Bind
LIT_INT            108
SEMICOLON          ;
... (30 more tokens)
RBRACE             }
```

---

## Architecture Highlights

### Token Categories
- **Keywords**: 30 tokens (KW_* prefix)
- **Operators**: 17 tokens (OP_* prefix)
- **Literals**: 4 tokens (LIT_INT, LIT_FLOAT, LIT_CHAR, LIT_STRING)
- **Identifiers**: 1 token (IDENTIFIER)
- **Punctuation**: 13 tokens (LPAREN, RPAREN, LBRACE, etc.)
- **Special**: Line tracking, error handling

### Key Files
- `jujutsu.l` contains:
  - Flex declarations and options
  - Token type enum (256-offset for Bison compatibility)
  - 77 lexical rules
  - Standalone `main()` for testing
  - TOKEN macro for output

### Rule Ordering
Carefully ordered to handle:
1. Comments (consumed)
2. Keywords (before identifiers)
3. Operators (longest-match first)
4. Literals (float before integer)
5. Identifiers
6. Punctuation
7. Whitespace
8. Errors

---

## Testing Coverage

### Unit Tests
- All 30 keywords: ✓ Verified
- All 17 operators: ✓ Verified
- Integer literals: ✓ Verified
- Float literals: ✓ Verified
- Character literals: ✓ Verified
- String literals: ✓ Verified
- Identifiers: ✓ Verified
- Punctuation (13 symbols): ✓ Verified

### Integration Tests
- Sample input (input.jjk): ✓ Passed
- Comprehensive test: ✓ Passed (191 tokens)
- Comment handling: ✓ Passed
- Error reporting: ✓ Passed

### Acceptance Tests
- All 11 criteria: ✓ Met

---

## For Future Phases

The lexer is designed to seamlessly integrate with Phase 2 (Bison parser):

1. **Token definitions** are in an enum - Bison will use `%token` instead
2. **`yylex()` returns tokens** - Standard for Bison integration
3. **Comments for `yylval`** - Ready for semantic values
4. **Standalone `main()`** - Can be replaced by Bison's parser
5. **Token output** can be removed, keeping only `return` statements

To integrate with Bison:
1. Create `.y` file with grammar rules
2. Remove `main()` from `.l` file
3. Replace `TOKEN()` macro output with just `return` statements
4. Link Flex and Bison output together

---

## Troubleshooting

### Build Issues
```bash
# Clean and rebuild
make clean && make

# Check Flex installation
flex --version

# Check G++ installation
g++ --version
```

### Compilation Warnings
All handled - `%option nounput` suppresses unused function warnings.

### Runtime Issues
- Ensure input file exists: `ls -la input.jjk`
- Check file permissions: `chmod +x jujutsu`
- Verify PATH: `./jujutsu` (use relative path)

---

## Contact & Support

**Project:** JujutsuLang Compiler
**Phase:** 1 (Lexical Analysis)
**Status:** ✓ Complete
**Date:** March 2026

For questions or issues, refer to:
- `PRD.md` for requirements
- `jujutsu.l` for implementation details
- `PHASE1_COMPLETE.md` for comprehensive documentation

---

## Summary

✓ **Phase 1 is complete and fully functional**
✓ **All 11 acceptance criteria met**
✓ **Ready for Phase 2 (Parser) development**
✓ **Thoroughly tested and documented**

The JujutsuLang lexer successfully tokenizes all valid JujutsuLang source code and provides comprehensive error reporting for invalid input.
