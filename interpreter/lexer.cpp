#include <string>
#include "lexer.hpp"

extern "C" {
#include "lexer.h"
}

int main() {
    scanner* _scanner = scanner_init("example.txt");
    scanner_all(_scanner);
    scanner_destroy(_scanner);

    return 0;
}