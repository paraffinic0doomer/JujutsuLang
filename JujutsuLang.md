# JujutsuLang — Language Specification

## 1. Keywords Mapping

| C Keyword     | JujutsuLang            | Reasoning / Logic                                              |
|---------------|------------------------|----------------------------------------------------------------|
| `int`         | `CursedEnergy`         | Numeric value, basic energy level.                             |
| `float`       | `ReversedFlow`         | Fractional or fine-tuned energy manipulation.                  |
| `double`      | `DomainPower`          | High-precision / large-scale numeric value.                    |
| `char`        | `SoulShard`            | Single character unit, smallest indivisible piece.             |
| `void`        | `NullVoid`             | Represents absence of return value.                            |
| `if`          | `TriggerCondition`     | Conditional execution based on a situation.                    |
| `else`        | `CounterMove`          | Alternative action if condition fails.                         |
| `switch`      | `ShikigamiSummon`      | Choose among multiple options.                                 |
| `case`        | `ShikigamiForm`        | Specific option in a switch.                                   |
| `for`         | `BindingLoop`          | Loop bound by a rule or condition (like a vow).                |
| `while`       | `CursedCycle`          | Repeats while a condition is true.                             |
| `do`          | `GuaranteedHit`        | Executes at least once, guaranteed action.                     |
| `break`       | `DomainShatter`        | Exit loop or switch early.                                     |
| `continue`    | `FlowShift`            | Skip current iteration, continue loop.                         |
| `return`      | `SukunaRelease`        | Send a value back from a function.                             |
| `struct`      | `CursedArtifact`       | Group of related variables (like a cursed object).             |
| `typedef`     | `ClanTechnique`        | Alias for a type, like a clan's signature move.                |
| `enum`        | `CurseRank`            | Enumerated types, like curse classification.                   |
| `const`       | `ImmutableSeal`        | Cannot change; permanent effect.                               |
| `static`      | `AnchoredSeal`         | Persistent across calls, stays in memory.                      |
| `extern`      | `RemoteCursedEnergy`   | Declared elsewhere, used externally.                           |
| `sizeof`      | `DomainScale`          | Measures size of an object/type.                               |
| `goto`        | `TeleportStrike`       | Jump to a specific point in code.                              |
| `main`        | `CursedBattle`         | Program entry point, main fight.                               |
| `union`       | `MergedCurse`          | Store different types in same memory space.                    |
| `volatile`    | `UnstableEnergy`       | Value can change unexpectedly.                                 |
| `register`    | `QuickStrike`          | Suggest to store in CPU register (fast access).                |
| `signed`      | `PositiveNegativeEnergy`| Can hold both positive and negative values.                   |
| `unsigned`    | `PureCursedEnergy`     | Only positive energy.                                          |
| `breakpoint*` | `CursedTrigger`       | Special debugging point (optional for your compiler).          |

## 2. Operators Mapping

| C Operator | JujutsuLang | Reasoning / Logic                            |
|------------|-------------|----------------------------------------------|
| `+`        | `Add`       | Increase energy/power.                       |
| `-`        | `Drain`     | Decrease energy/power.                       |
| `*`        | `Amplify`   | Multiply effect/power.                       |
| `/`        | `Divide`    | Split energy.                                |
| `%`        | `ShardMod`  | Modulo, remainder of attack/energy.          |
| `=`        | `Bind`      | Assign value.                                |
| `==`       | `Match`     | Check equality.                              |
| `!=`       | `Clash`     | Not equal, conflicting curse.                |
| `<`        | `Below`     | Less than.                                   |
| `>`        | `Above`     | Greater than.                                |
| `<=`       | `BelowEq`   | Less than or equal.                          |
| `>=`       | `AboveEq`   | Greater than or equal.                       |
| `&&`       | `Chain`     | Logical AND, like linking techniques.        |
| `\|\|`     | `Link`      | Logical OR, like connected techniques.       |
| `!`        | `Neg`       | Negation / cancel effect.                    |
| `++`       | `Boost`     | Increment energy.                            |
| `--`       | `Drain`     | Decrement energy.                            |
