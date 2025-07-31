#include "lexer_global.hpp"
#include "lexer_defined.hpp"

extern "C" {
#include "scanner.h"
}

int main() {
    scanner* _scanner = scanner_init("example.txt");
    scanner_all(_scanner);
    scanner_destroy(_scanner);

    return 0;
}