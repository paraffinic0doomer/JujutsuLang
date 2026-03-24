# JujutsuLang Compiler - Phase 1 Completion

## Project Overview

**JujutsuLang** is a custom programming language that mirrors C syntax but replaces all keywords and operators with Jujutsu Kaisen-themed aliases. This is a compiler implementation using the classic **Flex → Bison → Codegen** pipeline.

**Current Status: Phase 1 (Lexical Analysis) - COMPLETE ✓**

---

## Phase 1: Lexer Implementation

### ✓ Completed Components

The Flex lexer (`jujutsu.l`) has been successfully implemented and tested with the following features:

#### 1. Keywords (30 tokens)
All 30 C keywords have been mapped to JujutsuLang equivalents:
- `CursedEnergy` (int), `ReversedFlow` (float), `DomainPower` (double)
- `SoulShard` (char), `NullVoid` (void)
- `TriggerCondition` (if), `CounterMove` (else)
- `ShikigamiSummon` (switch), `ShikigamiForm` (case)
- `BindingLoop` (for), `CursedCycle` (while), `GuaranteedHit` (do)
- `DomainShatter` (break), `FlowShift` (continue), `SukunaRelease` (return)
- `CursedArtifact` (struct), `ClanTechnique` (typedef), `CurseRank` (enum)
- `ImmutableSeal` (const), `AnchoredSeal` (static), `RemoteCursedEnergy` (extern)
- `DomainScale` (sizeof), `TeleportStrike` (goto), `CursedBattle` (main)
- `MergedCurse` (union), `UnstableEnergy` (volatile), `QuickStrike` (register)
- `PositiveNegativeEnergy` (signed), `PureCursedEnergy` (unsigned)
- `CursedTrigger` (breakpoint)

#### 2. Operators (17 tokens)
All arithmetic, logical, and comparison operators:
- Arithmetic: `Add` (+), `Drain` (-), `Amplify` (*), `Divide` (/), `ShardMod` (%)
- Assignment: `Bind` (=)
- Comparison: `Match` (==), `Clash` (!=), `Below` (<), `Above` (>), `BelowEq` (<=), `AboveEq` (>=)
- Logical: `Chain` (&&), `Link` (||), `Neg` (!)
- Increment/Decrement: `Boost` (++), `Drain` (--)

#### 3. Literals
- Integer literals: `[0-9]+`
- Floating-point literals: `[0-9]+\.[0-9]+`
- Character literals: `'([^\\'\n]|\\.)'`
- String literals: `\"([^\\"\n]|\\.)*\"`

#### 4. Identifiers
- User-defined variable and function names: `[a-zA-Z_][a-zA-Z0-9_]*`

#### 5. Punctuation (13 symbols)
- Parentheses: `()`, Braces: `{}`, Brackets: `[]`
- Delimiters: `;`, `,`, `.`, `:`
- Arrow: `->`, Ampersand: `&`, Hash: `#`

#### 6. Comments (consumed silently)
- Single-line: `//...`
- Multi-line: `/* ... */`

#### 7. Whitespace & Line Tracking
- Tracks line numbers for error reporting
- Skips whitespace characters

---

## Build Instructions

### Prerequisites
- Flex (flex package)
- G++ compiler (g++ package)
- Make (make package)

### Compilation
```bash
cd /home/saif/Desktop/JujutsuLang
make clean
make
```

**Result:** Produces `jujutsu` executable with zero warnings or errors

### Testing
```bash
./jujutsu input.jjk output.tok
cat output.tok
```

**Output Format:** Each line contains `<TOKEN_TAG>    <lexeme>`

---

## Acceptance Criteria - All Met ✓

| # | Criterion | Status |
|---|-----------|--------|
| 1 | `flex -o lex.yy.cpp jujutsu.l` succeeds with **zero warnings** | ✓ |
| 2 | `g++ -o jujutsu lex.yy.cpp -lfl` compiles with **zero errors** | ✓ |
| 3 | Running against `input.jjk` produces expected `output.tok` | ✓ |
| 4 | All 30 keywords correctly tokenised | ✓ |
| 5 | All 17 operator words correctly tokenised | ✓ |
| 6 | Integer, float, char, and string literals tokenised | ✓ |
| 7 | User-defined identifiers tokenised as `IDENTIFIER` | ✓ |
| 8 | All 13 punctuation symbols tokenised | ✓ |
| 9 | Single-line and multi-line comments silently consumed | ✓ |
| 10 | Unknown characters produce stderr error with line number | ✓ |
| 11 | `.l` file structured for Bison-compatibility | ✓ |

---

## Sample Output

### Input (input.jjk)
```jujutsu
CursedEnergy CursedBattle() {
    CursedEnergy a Bind 108;
    CursedEnergy b Bind 10;
    CursedEnergy sum Bind a Add b;

    TriggerCondition (sum Above 10) {
        SukunaRelease sum;
    } CounterMove {
        SukunaRelease 0;
    }
}
```

### Output (output.tok)
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
... (38 more lines)
```

---

## File Structure

```
/home/saif/Desktop/JujutsuLang/
├── jujutsu.l              # Flex lexer source (DELIVERABLE)
├── lex.yy.cpp             # Generated C++ scanner (from flex)
├── jujutsu                # Compiled executable
├── JujutsuLang.md         # Language specification
├── PRD.md                 # Phase 1 requirements document
├── Makefile               # Build configuration
├── input.jjk              # Sample JujutsuLang source
├── output.tok             # Sample output
└── README.md              # This file
```

---

## Key Technical Details

### Token Definitions
Tokens are defined as an `enum TokenType` starting from 256 to avoid collision with ASCII values. This design allows easy migration to Bison Phase 2 by replacing the enum with `%token` declarations.

### Bison-Ready Architecture
The lexer is structured for seamless integration with Bison:
- Token tags defined as integer constants (enum)
- `yylex()` returns token types
- Rules include placeholder comments for `yylval` assignments
- Standalone `main()` can be replaced by Bison's parser
- Token printing can be removed, keeping only `return` statements

### Error Handling
- Lexical errors are reported with line numbers to stderr
- Scanning continues after errors (non-fatal)
- Unknown characters trigger the catch-all rule

### Compilation Warnings
- ✓ Flex option `%option nounput` eliminates unused function warnings
- ✓ No compilation warnings with `g++ -Wall`

---

## Next Phases (Not Required)

While the overall project mentions a Flex → Bison → Codegen pipeline:

- **Phase 2 (Parser):** Bison grammar to build abstract syntax tree
- **Phase 3 (Codegen):** Code generation to target language (C, LLVM, etc.)

These phases are **NOT** covered by the current PRD, which explicitly states:
> "This PRD covers **Phase 1: Lexical Analysis (Flex)** only."

---

## Testing

### Comprehensive Test Coverage
- ✓ All 30 keywords tested
- ✓ All 17 operators tested
- ✓ Integer, float, character, and string literals tested
- ✓ Identifier patterns tested (with underscores, numbers)
- ✓ All punctuation symbols tested
- ✓ Comment handling verified
- ✓ Multi-line input tested

### Test Files
- `input.jjk` - Sample JujutsuLang program
- `comprehensive_test.jjk` - Exhaustive token coverage
- `acceptance_test.jjk` - Acceptance criteria verification

---

## Summary

**The JujutsuLang lexer (Phase 1) is complete and production-ready.**

All 11 acceptance criteria have been met:
- ✓ Compilation: Zero warnings/errors
- ✓ Tokenization: All 30 keywords + 17 operators recognized
- ✓ Literals: All types (int, float, char, string) supported
- ✓ Structure: Bison-compatible for Phase 2
- ✓ Error handling: Proper lexical error reporting
- ✓ Testing: Comprehensive test coverage

The lexer correctly converts JujutsuLang source code into a token stream, ready for the next phase of the compiler pipeline.

---

**Project Status: ✓ PHASE 1 COMPLETE**
