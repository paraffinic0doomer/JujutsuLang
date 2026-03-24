# JujutsuLang — Lexer (Flex) PRD

## 1. Project Overview

**JujutsuLang** is a custom programming language whose syntax mirrors the C language but replaces all C keywords and operators with Jujutsu Kaisen–themed aliases. The project uses the classic **Flex → Bison → Codegen** compiler pipeline. This PRD covers **Phase 1: Lexical Analysis (Flex)** only.

### 1.1 Goal

Build a Flex lexer (`jujutsu.l`) that:

1. Reads a JujutsuLang source file via `yyin`.
2. Tokenises every lexeme — keywords, operators, literals, identifiers, punctuation, comments, and strings.
3. Writes a human-readable token stream to `yyout` (one token per line).
4. Produces a `lex.yy.cpp` (C++ output) that compiles with `g++`.

### 1.2 Toolchain

| Step | Command |
|------|---------|
| Generate scanner | `flex -o lex.yy.cpp jujutsu.l` |
| Compile | `g++ -o jujutsu lex.yy.cpp -lfl` |
| Run | `./jujutsu < input.jjk > output.tok` (or use `yyin`/`yyout` in `main()`) |

---

## 2. Complete Token Catalogue

Every token the lexer must recognise, grouped by category.

### 2.1 Keywords (30 tokens)

Each JujutsuLang keyword maps 1-to-1 to a C keyword. The lexer must match the **JujutsuLang name** (case-sensitive) and emit a token tag.

| JujutsuLang Keyword      | C Equivalent | Token Tag (for Bison)        |
|--------------------------|--------------|------------------------------|
| `CursedEnergy`           | `int`        | `KW_INT`                     |
| `ReversedFlow`           | `float`      | `KW_FLOAT`                   |
| `DomainPower`            | `double`     | `KW_DOUBLE`                  |
| `SoulShard`              | `char`       | `KW_CHAR`                    |
| `NullVoid`               | `void`       | `KW_VOID`                    |
| `TriggerCondition`       | `if`         | `KW_IF`                      |
| `CounterMove`            | `else`       | `KW_ELSE`                    |
| `ShikigamiSummon`        | `switch`     | `KW_SWITCH`                  |
| `ShikigamiForm`          | `case`       | `KW_CASE`                    |
| `BindingLoop`            | `for`        | `KW_FOR`                     |
| `CursedCycle`            | `while`      | `KW_WHILE`                   |
| `GuaranteedHit`          | `do`         | `KW_DO`                      |
| `DomainShatter`          | `break`      | `KW_BREAK`                   |
| `FlowShift`              | `continue`   | `KW_CONTINUE`                |
| `SukunaRelease`          | `return`     | `KW_RETURN`                  |
| `CursedArtifact`         | `struct`     | `KW_STRUCT`                  |
| `ClanTechnique`          | `typedef`    | `KW_TYPEDEF`                 |
| `CurseRank`              | `enum`       | `KW_ENUM`                    |
| `ImmutableSeal`          | `const`      | `KW_CONST`                   |
| `AnchoredSeal`           | `static`     | `KW_STATIC`                  |
| `RemoteCursedEnergy`     | `extern`     | `KW_EXTERN`                  |
| `DomainScale`            | `sizeof`     | `KW_SIZEOF`                  |
| `TeleportStrike`         | `goto`       | `KW_GOTO`                    |
| `CursedBattle`           | `main`       | `KW_MAIN`                    |
| `MergedCurse`            | `union`      | `KW_UNION`                   |
| `UnstableEnergy`         | `volatile`   | `KW_VOLATILE`                |
| `QuickStrike`            | `register`   | `KW_REGISTER`                |
| `PositiveNegativeEnergy` | `signed`     | `KW_SIGNED`                  |
| `PureCursedEnergy`       | `unsigned`   | `KW_UNSIGNED`                |
| `CursedTrigger`          | `breakpoint` | `KW_BREAKPOINT` *(optional)* |

### 2.2 Operators (17 tokens)

Multi-character operators (`Boost`, `Drain` for `--`, `Match`, `Clash`, `BelowEq`, `AboveEq`, `Chain`, `Link`) **must be matched before** single-character ones to avoid ambiguity. Flex's longest-match rule handles this automatically since these are literal strings.

| JujutsuLang Operator | C Equivalent | Token Tag         |
|----------------------|--------------|-------------------|
| `Add`                | `+`          | `OP_ADD`          |
| `Drain`              | `-`          | `OP_SUB`          |
| `Amplify`            | `*`          | `OP_MUL`          |
| `Divide`             | `/`          | `OP_DIV`          |
| `ShardMod`           | `%`          | `OP_MOD`          |
| `Bind`               | `=`          | `OP_ASSIGN`       |
| `Match`              | `==`         | `OP_EQ`           |
| `Clash`              | `!=`         | `OP_NEQ`          |
| `Below`              | `<`          | `OP_LT`           |
| `Above`              | `>`          | `OP_GT`           |
| `BelowEq`            | `<=`         | `OP_LTE`          |
| `AboveEq`            | `>=`         | `OP_GTE`          |
| `Chain`              | `&&`         | `OP_AND`          |
| `Link`               | `\|\|`       | `OP_OR`           |
| `Neg`                | `!`          | `OP_NOT`          |
| `Boost`              | `++`         | `OP_INC`          |
| `Drain`              | `--`         | `OP_DEC`          |

> **Note on `Drain`:** The word `Drain` appears for both `-` (subtract) and `--` (decrement). The lexer must distinguish context:
> - If `Drain` appears as a **standalone word** (surrounded by whitespace / delimiters), it is **`OP_SUB`** (single minus).
> - `Drain` used as `--` (decrement) also maps to `Drain`. Since both are the same literal string, use **one rule** that matches the word `Drain` and outputs `OP_DRAIN`. Bison will later decide from context whether it's subtraction or decrement.  
> Alternatively, if the user intends them as separate tokens, they can introduce `DoubleDrain` for `--`. For now, **treat all `Drain` as a single `OP_DRAIN` token**.

### 2.3 Literals

| Literal Type          | Regex Pattern                        | Token Tag       | Examples                    |
|-----------------------|--------------------------------------|-----------------|-----------------------------|
| Integer literal       | `[0-9]+`                             | `LIT_INT`       | `0`, `42`, `1000`          |
| Float literal         | `[0-9]+\.[0-9]+`                     | `LIT_FLOAT`     | `3.14`, `0.5`              |
| Character literal     | `\'([^\\'\n]|\\.)'`                  | `LIT_CHAR`      | `'a'`, `'\n'`              |
| String literal        | `\"([^\\"\n]|\\.)*\"`                | `LIT_STRING`    | `"hello"`, `"domain\n"`    |

### 2.4 Identifiers

Any user-defined name (variable, function) that is **not** a keyword or operator word.

| Pattern                   | Token Tag    | Examples                |
|---------------------------|--------------|-------------------------|
| `[a-zA-Z_][a-zA-Z0-9_]*` | `IDENTIFIER` | `myVar`, `_count`, `x1` |

> **Rule ordering:** All keyword and operator-word rules must appear **before** the identifier rule in the `.l` file so that reserved words are never misclassified as identifiers.

### 2.5 Punctuation / Delimiters

These remain as standard C punctuation (not renamed).

| Symbol | Token Tag        |
|--------|------------------|
| `(`    | `LPAREN`         |
| `)`    | `RPAREN`         |
| `{`    | `LBRACE`         |
| `}`    | `RBRACE`         |
| `[`    | `LBRACKET`       |
| `]`    | `RBRACKET`       |
| `;`    | `SEMICOLON`      |
| `,`    | `COMMA`          |
| `.`    | `DOT`            |
| `:`    | `COLON`          |
| `->`   | `ARROW`          |
| `&`    | `AMPERSAND`      |
| `#`    | `HASH`           |

### 2.6 Comments (consumed, not tokenised)

| Style              | Pattern                  | Action         |
|--------------------|--------------------------|----------------|
| Single-line        | `\/\/[^\n]*`             | Skip (no emit) |
| Multi-line         | `\/\*([^*]|\*+[^*/])*\*+\/` | Skip (no emit) |

### 2.7 Whitespace

| Pattern            | Action         |
|--------------------|----------------|
| `[ \t\r]+`         | Skip (no emit) |
| `\n`               | Increment line counter, skip |

---

## 3. Lexer Architecture & Requirements

### 3.1 File Structure (`jujutsu.l`)

```
%{
    /* C++ declarations: includes, line counter, helper macros */
%}

%option noyywrap

    /* Optional: named regex definitions */

%%
    /* --- RULES SECTION (order matters) --- */
    /* 1. Comments          (skip)           */
    /* 2. Keywords          (emit token)     */
    /* 3. Operator words    (emit token)     */
    /* 4. Literals          (emit token)     */
    /* 5. Identifiers       (emit token)     */
    /* 6. Punctuation       (emit token)     */
    /* 7. Whitespace/newline(skip / count)   */
    /* 8. Catch-all         (error report)   */
%%

int main(int argc, char* argv[]) {
    /* Open input file → yyin   */
    /* Open output file → yyout */
    /* Call yylex()             */
    /* Close files              */
    return 0;
}
```

### 3.2 Output Format (to `yyout`)

Each recognised token is printed as **one line** to `yyout`:

```
<TOKEN_TAG>        <lexeme>
```

Example — given this JujutsuLang source:

```
CursedEnergy CursedBattle() {
    CursedEnergy x Bind 10;
    SukunaRelease x;
}
```

Expected `yyout`:

```
KW_INT             CursedEnergy
KW_MAIN            CursedBattle
LPAREN             (
RPAREN             )
LBRACE             {
KW_INT             CursedEnergy
IDENTIFIER         x
OP_ASSIGN          Bind
LIT_INT            10
SEMICOLON          ;
KW_RETURN          SukunaRelease
IDENTIFIER         x
SEMICOLON          ;
RBRACE             }
```

### 3.3 Error Handling

- Any character that does not match any rule should trigger a **catch-all** rule.
- Print to `stderr`: `Lexical Error at line <N>: unexpected character '<c>'`
- Continue scanning (do not abort).

### 3.4 Line Tracking

- Maintain an `int line_number = 1;` counter.
- Increment on every `\n`.
- Include line number in error messages.
- Optionally include line number in token output: `<TOKEN_TAG>  <line>  <lexeme>`.

---

## 4. Build & Run Instructions

### 4.1 File Layout

```
JujutsuLang/
├── jujutsu.l            # Flex source (this PRD's deliverable)
├── JujutsuLang.md       # Language spec (keywords + operators)
├── PRD.md               # This file
├── input.jjk            # Sample JujutsuLang source (test file)
└── Makefile             # (optional) build automation
```

### 4.2 Build Steps

```bash
flex -o lex.yy.cpp jujutsu.l          # Generate C++ scanner
g++ -o jujutsu lex.yy.cpp -lfl        # Compile scanner
```

### 4.3 Run

```bash
./jujutsu input.jjk output.tok        # Reads input.jjk → writes output.tok
```

Or, if `main()` uses `yyin`/`yyout` with command-line args:

```bash
./jujutsu <input_file> <output_file>
```

---

## 5. Bison-Readiness Constraints

Even though Bison is Phase 2, the lexer **must** be designed so it plugs directly into Bison later:

| Constraint | Detail |
|------------|--------|
| **Token tags as `#define` or `enum`** | Each `TOKEN_TAG` (e.g., `KW_INT`, `OP_ADD`) should be defined as an integer constant. For Phase 1 (standalone), define them in the `%{ %}` block. In Phase 2, Bison's `.y` file will generate these via `%token` declarations. |
| **`yylex()` return values** | Each rule's action should `return TOKEN_TAG;` so Bison can consume them. For Phase 1 standalone testing, the `main()` calls `yylex()` in a loop and prints the token. |
| **`yylval` support** | For literals and identifiers, store the value in `yylval` (a union). Phase 1 can skip this, but the rules should have placeholder comments showing where `yylval` assignment goes. |
| **No `main()` in Bison mode** | The `main()` in the `.l` file is for standalone testing only. When integrating with Bison, `main()` will live in the `.y` file instead. |

---

## 6. Sample Input / Output

### `input.jjk`

```jjk
// This is a JujutsuLang program
CursedEnergy CursedBattle() {
    CursedEnergy a Bind 5;
    CursedEnergy b Bind 10;
    CursedEnergy sum Bind a Add b;

    TriggerCondition (sum Above 10) {
        SukunaRelease sum;
    } CounterMove {
        SukunaRelease 0;
    }
}
```

### Expected `output.tok`

```
KW_INT             CursedEnergy
KW_MAIN            CursedBattle
LPAREN             (
RPAREN             )
LBRACE             {
KW_INT             CursedEnergy
IDENTIFIER         a
OP_ASSIGN          Bind
LIT_INT            5
SEMICOLON          ;
KW_INT             CursedEnergy
IDENTIFIER         b
OP_ASSIGN          Bind
LIT_INT            10
SEMICOLON          ;
KW_INT             CursedEnergy
IDENTIFIER         sum
OP_ASSIGN          Bind
IDENTIFIER         a
OP_ADD             Add
IDENTIFIER         b
SEMICOLON          ;
KW_IF              TriggerCondition
LPAREN             (
IDENTIFIER         sum
OP_GT              Above
LIT_INT            10
RPAREN             )
LBRACE             {
KW_RETURN          SukunaRelease
IDENTIFIER         sum
SEMICOLON          ;
RBRACE             }
KW_ELSE            CounterMove
LBRACE             {
KW_RETURN          SukunaRelease
LIT_INT            0
SEMICOLON          ;
RBRACE             }
RBRACE             }
```

---

## 7. Acceptance Criteria

1. `flex -o lex.yy.cpp jujutsu.l` succeeds with **zero warnings**.
2. `g++ -o jujutsu lex.yy.cpp -lfl` compiles with **zero errors**.
3. Running against `input.jjk` produces the exact expected `output.tok`.
4. All 30 keywords are correctly tokenised.
5. All 17 operator words are correctly tokenised.
6. Integer, float, char, and string literals are tokenised.
7. User-defined identifiers are tokenised as `IDENTIFIER`.
8. All 13 punctuation symbols are tokenised.
9. Single-line and multi-line comments are silently consumed.
10. Unknown characters produce a `stderr` error with the line number, and scanning continues.
11. The `.l` file is structured so that replacing the standalone `main()` and token prints with `return TOKEN_TAG;` statements makes it Bison-compatible with minimal changes.
