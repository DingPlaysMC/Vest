#include <string>
#include "lexer.hpp"

extern "C" {
#include "lexer.h"
}

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

void scanner_destroy(scanner* s) {
    if (s->pFile) {
        free(s);
        fclose(s->pFile);
        s->pFile = NULL;
    }
}

_EXPORT_C scanner* __cdecl wscanner_init(const char* filename) {
    scanner_init(filename);
}

_EXPORT_C void __cdecl wscanner_destroy(scanner* s) {
    scanner_destroy(s);
}

int main() {
    scanner* _scanner = wscanner_init("example.txt");
    scanner_all(_scanner);
    wscanner_destroy(_scanner);

    return 0;
}