#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _EXPORT_C extern "C"

#define _STR 257
#define _LBRACK 258
#define _RBRACK 259
#define _LBRACE 260
#define _RBRACE 261
#define _COLON 262
#define _SEMICOLON 263
#define _COMMA 264
#define _SPCE 265
#define _STOP 266
#define _IDEN 267
#define _NUM 268
#define _KEY 269

typedef struct {
    char* pFile;
    int lineno;
} scanner;

typedef struct {
    int token_type;
    void* content;
} token;

enum keyword{
    _INT = 512,
    _DOUBLE,
    _FLOAT,
    _BOOL,
    _STRING,
    _CHAR,
    _VOID,
    _SET,
    _JSON,
    _OPERATOR,
    _KEYWORD,
    _STRUCT,
    _CODEARRAY,
    _CLASS,
    _PUBLIC,
    _PRIVATE,
    _FINAL,
    _IMPORT,
    _IMPORTEX,
    _UNKNOWN = -1
};

_EXPORT_C keyword _cdecl wget_token_type(char* str);

#ifdef __cplusplus
}
#endif

// Test for exporting a function to C
// It worked! :)
_EXPORT_C int __cdecl add(int a, int b) {
    return a + b;
}