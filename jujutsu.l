/* ================================================================== */
/*  jujutsu.l — Flex lexer for JujutsuLang                            */
/*  Phase 1: Standalone tokeniser (Bison-ready)                       */
/*                                                                    */
/*  Build:                                                            */
/*      flex -o lex.yy.cpp jujutsu.l                                  */
/*      g++ -o jujutsu lex.yy.cpp -lfl                                */
/*  Run:                                                              */
/*      ./jujutsucc input.jjk                                */
/* ================================================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jujutsu.tab.h"

/* ------------------------------------------------------------------ */
/*  Line tracking                                                      */
/* ------------------------------------------------------------------ */
int line_number = 1;


/* ------------------------------------------------------------------ */
/*  Token tag definitions removed — Bison provides them via           */
/*  jujutsu.tab.h generated from jujutsu.y                            */
/* ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ */
/*  TOKEN macro — returns tag to Bison / prints for Phase 1           */
/*  In Phase 2 (Bison mode), yy_current_buffer is not in standalone   */
/*  mode, so we suppress output.                                       */
/* ------------------------------------------------------------------ */
#define TOKEN(tag) do { \
    return tag; \
} while (0)

%}

    /* Flex options */
%option noyywrap
%option nounput

    /* Start condition for multi-line comments */
%x COMMENT

%%

    /* ============================================================== */
    /*  1. COMMENTS  (consumed silently)                               */
    /* ============================================================== */

"//"[^\n]*              { /* single-line comment — skip */ }
"/*"                    { BEGIN(COMMENT); }
<COMMENT>"*/"           { BEGIN(INITIAL); }
<COMMENT>\n             { line_number++; }
<COMMENT>.              { /* skip comment body */ }

    /* ============================================================== */
    /*  2. KEYWORDS  (30 rules — must appear before identifiers)       */
    /* ============================================================== */

"CursedEnergy"              { TOKEN(KW_INT); }
"ReversedFlow"              { TOKEN(KW_FLOAT); }
"DomainPower"               { TOKEN(KW_DOUBLE); }
"SoulShard"                 { TOKEN(KW_CHAR); }
"NullVoid"                  { TOKEN(KW_VOID); }
"TriggerCondition"          { TOKEN(KW_IF); }
"CounterMove"               { TOKEN(KW_ELSE); }
"ShikigamiSummon"           { TOKEN(KW_SWITCH); }
"ShikigamiForm"             { TOKEN(KW_CASE); }
"BindingLoop"               { TOKEN(KW_FOR); }
"CursedCycle"               { TOKEN(KW_WHILE); }
"GuaranteedHit"             { TOKEN(KW_DO); }
"DomainShatter"             { TOKEN(KW_BREAK); }
"FlowShift"                 { TOKEN(KW_CONTINUE); }
"SukunaRelease"             { TOKEN(KW_RETURN); }
"CursedArtifact"            { TOKEN(KW_STRUCT); }
"ClanTechnique"             { TOKEN(KW_TYPEDEF); }
"CurseRank"                 { TOKEN(KW_ENUM); }
"ImmutableSeal"             { TOKEN(KW_CONST); }
"AnchoredSeal"              { TOKEN(KW_STATIC); }
"RemoteCursedEnergy"        { TOKEN(KW_EXTERN); }
"DomainScale"               { TOKEN(KW_SIZEOF); }
"TeleportStrike"            { TOKEN(KW_GOTO); }
"CursedBattle"              { TOKEN(KW_MAIN); }
"MergedCurse"               { TOKEN(KW_UNION); }
"UnstableEnergy"            { TOKEN(KW_VOLATILE); }
"QuickStrike"               { TOKEN(KW_REGISTER); }
"PositiveNegativeEnergy"    { TOKEN(KW_SIGNED); }
"PureCursedEnergy"          { TOKEN(KW_UNSIGNED); }
"CursedTrigger"             { TOKEN(KW_BREAKPOINT); }
"CursedPrint"               { TOKEN(KW_PRINTF); }
"CursedScan"                { TOKEN(KW_SCANF); }

    /* ============================================================== */
    /*  3. OPERATOR WORDS  (16 rules)                                  */
    /*  Longer names (BelowEq, AboveEq, ShardMod) are listed first    */
    /*  as good practice, though Flex's longest-match handles it.      */
    /* ============================================================== */

"BelowEq"                   { TOKEN(OP_LTE); }
"AboveEq"                   { TOKEN(OP_GTE); }
"ShardMod"                  { TOKEN(OP_MOD); }
"Amplify"                   { TOKEN(OP_MUL); }
"Divide"                    { TOKEN(OP_DIV); }
"Match"                     { TOKEN(OP_EQ); }
"Clash"                     { TOKEN(OP_NEQ); }
"Chain"                     { TOKEN(OP_AND); }
"Boost"                     { TOKEN(OP_INC); }
"Drain"                     { TOKEN(OP_DRAIN); }
"Below"                     { TOKEN(OP_LT); }
"Above"                     { TOKEN(OP_GT); }
"Bind"                      { TOKEN(OP_ASSIGN); }
"Link"                      { TOKEN(OP_OR); }
"Add"                       { TOKEN(OP_ADD); }
"Neg"                       { TOKEN(OP_NOT); }

    /* ============================================================== */
    /*  4. LITERALS                                                    */
    /*  Float before Integer so "3.14" is not split into "3" + ".14"  */
    /* ============================================================== */

[0-9]+\.[0-9]+              { yylval.fval = atof(yytext);    TOKEN(LIT_FLOAT); }
[0-9]+                      { yylval.ival = atoi(yytext);    TOKEN(LIT_INT); }
'([^\\'\n]|\\.)'            { yylval.cval = yytext[1];       TOKEN(LIT_CHAR); }
\"([^\\"\n]|\\.)*\"         { yylval.sval = strdup(yytext);  TOKEN(LIT_STRING); }

    /* ============================================================== */
    /*  5. IDENTIFIERS  (must come AFTER all keywords & operators)     */
    /* ============================================================== */

[a-zA-Z_][a-zA-Z0-9_]*     { yylval.sval = strdup(yytext);  TOKEN(IDENTIFIER); }

    /* ============================================================== */
    /*  6. PUNCTUATION / DELIMITERS  (13 rules)                        */
    /*  "->" before any single-char rule to avoid matching "-" alone.  */
    /* ============================================================== */

"->"                        { TOKEN(ARROW); }
"("                         { TOKEN(LPAREN); }
")"                         { TOKEN(RPAREN); }
"{"                         { TOKEN(LBRACE); }
"}"                         { TOKEN(RBRACE); }
"["                         { TOKEN(LBRACKET); }
"]"                         { TOKEN(RBRACKET); }
";"                         { TOKEN(SEMICOLON); }
","                         { TOKEN(COMMA); }
"."                         { TOKEN(DOT); }
":"                         { TOKEN(COLON); }
"&"                         { TOKEN(AMPERSAND); }
"#"                         { TOKEN(HASH); }

    /* ============================================================== */
    /*  7. WHITESPACE & NEWLINES                                       */
    /* ============================================================== */

\n                          { line_number++; }
[ \t\r]+                    { /* skip horizontal whitespace */ }

    /* ============================================================== */
    /*  8. CATCH-ALL — lexical error                                   */
    /* ============================================================== */

.                           { fprintf(stderr,
                                "Lexical Error at line %d: unexpected character '%s'\n",
                                line_number, yytext); }

%%

/* ================================================================== */
/*  main() — standalone driver for Phase 1 testing.                    */
/*  In Phase 2 (Bison), DELETE this function; main() moves to .y      */
/* ================================================================== */
/* ================================================================== */
/*  main() — Driver (Phase 1 standalone only)                         */
/*  Removed for Phase 2 since Bison provides main()                   */
/* ================================================================== */


