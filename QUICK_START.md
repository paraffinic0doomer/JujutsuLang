# JujutsuLang Compiler — Quick Start Guide

## Installation & Building

### Prerequisites
- Linux/Unix environment
- GCC/G++ compiler
- Flex (lexer generator)
- Bison (parser generator)
- GNU Make

### Installation on Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install flex bison g++ make
```

### Installation on macOS
```bash
brew install flex bison gcc
```

### Installation on RHEL/CentOS
```bash
sudo yum install flex bison gcc-c++ make
```

## Building the Compiler

### Quick Build
```bash
cd /home/saif/Desktop/JujutsuLang
make clean
make parser      # Builds Phase 1 (Lexer) + Phase 2 (Parser)
```

### Alternative Builds
```bash
# Build only Phase 1 (Flex lexer)
make lexer

# Show available targets
make help

# Remove build artifacts
make clean
```

### Expected Output
```
bison -d jujutsu.y
jujutsu.y: warning: 1 nonterminal useless in grammar [-Wother]
jujutsu.y: warning: 1 shift/reduce conflict [-Wconflicts-sr]
flex -o lex.yy.c jujutsu.l
g++ -Wall -Wno-deprecated -x c++ -o jujutsu jujutsu.tab.c lex.yy.c -lfl
Built Phase 2 (Parser): jujutsu
```

**Note**: Warnings are non-critical and expected.

## Running the Compiler

### Basic Usage
```bash
./jujutsu <input_file.jjk>
```

### Examples

#### Example 1: Variable Declaration
```bash
# Create test file
cat > test1.jjk << 'EOF'
CursedEnergy x;
CursedEnergy y Bind 10;
EOF

# Run compiler
./jujutsu test1.jjk
```

**Output:**
```
=== JujutsuLang Parser - Phase 2 ===
Parsing: test1.jjk

Variable declared: x
Variable declared and assigned: y = 10

=== Parsing Complete ===
```

#### Example 2: Function Definition
```bash
# Create test file
cat > test2.jjk << 'EOF'
CursedEnergy add(CursedEnergy a, CursedEnergy b) {
    CursedEnergy result Bind a Add b;
    SukunaRelease result;
}
EOF

# Run compiler
./jujutsu test2.jjk
```

**Output:**
```
=== JujutsuLang Parser - Phase 2 ===
Parsing: test2.jjk

Compound statement executed
Function defined: add (with parameters)

=== Parsing Complete ===
```

#### Example 3: Variable Assignment & Expression
```bash
# Create test file
cat > test3.jjk << 'EOF'
CursedEnergy x Bind 5;
CursedEnergy y Bind 3;
CursedEnergy z Bind x Add y;
EOF

# Run compiler
./jujutsu test3.jjk
```

**Output:**
```
=== JujutsuLang Parser - Phase 2 ===
Parsing: test3.jjk

Variable declared and assigned: x = 5
Variable declared and assigned: y = 3
Variable declared: z
Variable reference: x = 5
Variable reference: y = 3
Addition: 5 + 3 = 8
Assignment: z = 8

=== Parsing Complete ===
```

#### Example 4: Conditional Statements
```bash
# Create test file
cat > test4.jjk << 'EOF'
CursedEnergy x Bind 10;
TriggerCondition (x Above 5) {
    SukunaRelease x;
} CounterMove {
    SukunaRelease 0;
}
EOF

# Run compiler
./jujutsu test4.jjk
```

**Output:**
```
=== JujutsuLang Parser - Phase 2 ===
Parsing: test4.jjk

Variable declared and assigned: x = 10
Greater than: 10 > 5 = 1
If statement: condition evaluated

=== Parsing Complete ===
```

## JujutsuLang Syntax Guide

### Keywords Reference

| Keyword | Meaning | Equivalent |
|---------|---------|------------|
| CursedEnergy | Integer type | int |
| ReversedFlow | Float type | float |
| DomainPower | Double type | double |
| SoulShard | Character type | char |
| NullVoid | Void type | void |
| TriggerCondition | If statement | if |
| CounterMove | Else clause | else |
| ShikigamiSummon | Switch statement | switch |
| ShikigamiForm | Case label | case |
| BindingLoop | For loop | for |
| CursedCycle | While loop | while |
| GuaranteedHit | Do-while loop | do |
| DomainShatter | Break statement | break |
| FlowShift | Continue statement | continue |
| SukunaRelease | Return statement | return |
| CursedArtifact | Struct definition | struct |
| ClanTechnique | Typedef definition | typedef |
| CurseRank | Enum definition | enum |
| ImmutableSeal | Const modifier | const |
| AnchoredSeal | Static modifier | static |
| RemoteCursedEnergy | Extern modifier | extern |
| DomainScale | Sizeof operator | sizeof |
| TeleportStrike | Goto statement | goto |
| CursedBattle | Main function | void main() |
| MergedCurse | Union type | union |
| UnstableEnergy | Volatile modifier | volatile |
| QuickStrike | Register modifier | register |
| PositiveNegativeEnergy | Signed modifier | signed |
| PureCursedEnergy | Unsigned modifier | unsigned |
| CursedTrigger | Breakpoint | breakpoint |

### Operators Reference

| Operator | Symbol | Example |
|----------|--------|---------|
| Addition | Add | x Add y |
| Subtraction | Drain | x Drain y |
| Multiplication | Amplify | x Amplify y |
| Division | Divide | x Divide y |
| Modulo | ShardMod | x ShardMod y |
| Assignment | Bind | x Bind 10 |
| Equality | SoulUnite | x SoulUnite y |
| Inequality | SoulSeparate | x SoulSeparate y |
| Less than | Below | x Below y |
| Greater than | Above | x Above y |
| Less or equal | BelowEq | x BelowEq y |
| Greater or equal | AboveEq | x AboveEq y |
| Logical AND | SoulChain | x SoulChain y |
| Logical OR | SoulMeld | x SoulMeld y |
| Logical NOT | CursedBreak | CursedBreak x |
| Increment | (++) | x ++ |

### Basic Program Structure

```jujutsu
// Single-line comment
/* Multi-line
   comment */

// Variable declarations
CursedEnergy x;           // uninitialized
CursedEnergy y Bind 10;   // initialized

// Function definition
CursedEnergy add(CursedEnergy a, CursedEnergy b) {
    CursedEnergy result Bind a Add b;
    SukunaRelease result;
}

// Function call
CursedEnergy sum Bind add(5, 3);

// Conditional
TriggerCondition (sum Above 5) {
    SukunaRelease sum;
} CounterMove {
    SukunaRelease 0;
}

// Loop
BindingLoop (CursedEnergy i Bind 0; i Below 10; i OP_INC) {
    // Loop body
}
```

## Debugging & Troubleshooting

### Issue: "flex: command not found"
**Solution**: Install Flex
```bash
sudo apt-get install flex    # Ubuntu/Debian
brew install flex            # macOS
```

### Issue: "bison: command not found"
**Solution**: Install Bison
```bash
sudo apt-get install bison   # Ubuntu/Debian
brew install bison           # macOS
```

### Issue: "g++: command not found"
**Solution**: Install G++
```bash
sudo apt-get install g++     # Ubuntu/Debian
brew install gcc             # macOS
```

### Issue: Compilation fails with "error: jujutsu.tab.h: No such file or directory"
**Solution**: Clean and rebuild
```bash
make clean
make parser
```

### Issue: Parser produces "Syntax Error" unexpectedly
**Check**:
1. Verify source file uses JujutsuLang keywords (not C keywords)
   - Use `CursedEnergy` not `int`
   - Use `Bind` not `=`
   - Use `TriggerCondition` not `if`

2. Check for missing semicolons:
   ```jujutsu
   CursedEnergy x;  // ✓ Correct
   CursedEnergy x   // ✗ Missing semicolon
   ```

3. Ensure proper brace matching:
   ```jujutsu
   {
       // statement
   }  // ✓ Balanced
   ```

### Issue: Undefined variable or function warning
**Solution**: Declare before use
```jujutsu
CursedEnergy x;      // Must declare first
x Bind 10;           // Then assign
```

## Test Files Included

The workspace includes pre-built test files:

1. **input.jjk** - Original complex example (function definition with if-else)
2. **test_simple.jjk** - Simple variable declaration
3. **test_func.jjk** - Function definition with empty body
4. **test_phase2.jjk** - C-style syntax test

### Run All Tests
```bash
echo "=== Test 1: Simple Variable ==="
./jujutsu test_simple.jjk

echo -e "\n=== Test 2: Function Definition ==="
./jujutsu test_func.jjk

echo -e "\n=== Test 3: Complex Program ==="
./jujutsu input.jjk
```

## File Organization

```
Project Directory:
├── jujutsu              # Compiled executable
├── jujutsu.l            # Flex lexer source
├── jujutsu.y            # Bison parser source
├── lex.yy.c             # Generated lexer (auto)
├── jujutsu.tab.c        # Generated parser (auto)
├── jujutsu.tab.h        # Generated headers (auto)
├── Makefile             # Build configuration
├── *.jjk                # JujutsuLang source files
├── *.md                 # Documentation
└── exec_engine.py       # Python execution engine
```

## Build System Details

### Makefile Targets

```makefile
# Main targets
make parser              # Build complete compiler (Lexer + Parser)
make lexer              # Build lexer only
make test               # Run test on input.jjk
make clean              # Remove generated files
make help               # Show available targets
```

### Build Flags

```
CXXFLAGS = -Wall -Wno-deprecated -x c++
```

- `-Wall`: Show all compiler warnings
- `-Wno-deprecated`: Suppress deprecation warnings
- `-x c++`: Treat C files as C++ (enables std::map)

## Performance Tips

### For Large Programs
1. The parser is optimized for typical program sizes (< 10,000 lines)
2. Symbol table uses binary search tree (efficient lookup)
3. Lexer uses DFA (optimal for tokenization)

### For Development
1. Use `make clean` before rebuilding after source changes
2. Test incrementally with small test files
3. Check parser output for correctness before expanding programs

## Documentation

### Comprehensive Documentation Files

1. **PROJECT_SUMMARY.md** - Complete project overview
2. **PHASE2_PARSER.md** - Detailed parser documentation
3. **PHASE3_EXECUTION.md** - Execution engine specifications
4. **JujutsuLang.md** - Language specification
5. **PRD.md** - Project requirements document

### Reading Guide
- **Start here**: PROJECT_SUMMARY.md
- **Parser details**: PHASE2_PARSER.md
- **Execution details**: PHASE3_EXECUTION.md
- **Language reference**: JujutsuLang.md

## Support & Help

### Common Questions

**Q: How do I use custom variable names?**
A: Use JujutsuLang keyword for type, then any valid identifier:
```jujutsu
CursedEnergy myVariable Bind 42;
CursedEnergy _private Bind 0;
```

**Q: Can I have nested functions?**
A: Current implementation supports function definitions at global scope only.

**Q: What's the maximum nesting depth?**
A: Limited primarily by system stack size; practical limit ~100+ levels.

**Q: Do I need the Python execution engine?**
A: No, it's optional documentation. The C++ implementation in Bison handles everything.

## Summary

The JujutsuLang Compiler is now ready for use! Follow these steps:

1. **Build**: `make parser`
2. **Test**: `./jujutsu test_simple.jjk`
3. **Create Programs**: Write .jjk files with JujutsuLang syntax
4. **Compile**: `./jujutsu yourprogram.jjk`
5. **View Output**: Check the execution trace

For more information, see the comprehensive documentation files included in the project directory.

---

**Happy Compiling with JujutsuLang!**

