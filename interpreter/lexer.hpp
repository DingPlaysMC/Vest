#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _EXPORT_C extern "C"

#define _STRING 257
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

typedef struct {
    FILE* pFile;
    int lineno;
} scanner;

// Initialize scanner
scanner* scanner_init(const char* filename) {
    scanner* s = (scanner*)malloc(sizeof(scanner));
    if (!s) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    s->pFile = fopen(filename, "r");
    s->lineno = 1;
    if (!s->pFile) {
        fprintf(stderr, "Error opening file.\n");
    }
    return s;
}

// Destroy scanner
void scanner_destroy(scanner* s) {
    if (s->pFile) {
        free(s);
        fclose(s->pFile);
        s->pFile = NULL;
    }
}

#ifdef __cplusplus
}
#endif

// Test for exporting a function to C
// It worked! :)
_EXPORT_C int __cdecl add(int a, int b) {
    return a + b;
}