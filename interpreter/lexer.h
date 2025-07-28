#pragma once

#include "lexer.hpp"

typedef struct{
    char* str;
    int startcol;
    int endcol;
}strpos;

inline bool isletter(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Read next line and print tokens
int scanner_nextline(scanner* s) {
    if (!s->pFile) return 1;
    char _this;
    bool _retainflg = false;
    int _col = 1;
    strpos* _pos;

    while(_this = fgetc(s->pFile)) {
        switch(_this){
            case '\'':
            {
                _pos = (strpos*)malloc(sizeof(strpos));
                memset(_pos->str, 0, 101);
                _pos->str[0] = _this;
                _pos->startcol = _col;
                int _off;
                bool _conflg = false;
                for(_off = 1;;_off++) {
                    if ((&_this+_off) != NULL){
                        char _tmp = *(&_this+_off);
                        printf("Debug: _tmp = %c , _off = %d\n", _tmp, _off);
                        if (_tmp == '\'') {
                            _pos->endcol = _col-1;
                            break;
                        }
                        if (_tmp == EOF || _tmp == '\n'){
                            // shit, this is not done
                            fprintf(stderr, "Error: Can't close the string at line %d, column %d", s->lineno, _col);
                            _conflg = true;
                            break;
                        }
                    }else{
                        fprintf(stderr, "Error: Can't close the string at line %d, column %d", s->lineno, _col);
                        _conflg = true;
                        break;
                    }
                }
                if (_conflg == false){
                    for(int i = 0; i<_off; i++){
                        size_t len = strlen(_pos->str);
                        if(len < 100) {
                            _pos->str[len] = fgetc(s->pFile);
                            _pos->str[len+1] = '\0';
                        }
                    }
                }
                free(_pos);
                break;
            }
            case '"':
                // Copy & Paste above
                break;
            case 'A'...'Z':
            case 'a'...'z':
                if (!_retainflg){
                    _retainflg = true;
                    _pos = (strpos*)malloc(sizeof(strpos));
                    if(_pos == NULL){
                        fprintf(stderr, "Memory allocation failed.\n");
                        return 1;
                    }
                    _pos->str = new char[101];
                    memset(_pos->str, 0, 101);
                    _pos->str[0] = _this;
                    _pos->startcol = _col;
                }else{
                    size_t len = strlen(_pos->str);
                    if(len < 100) {
                        _pos->str[len] = _this;
                        _pos->str[len+1] = '\0';
                    }
                }
                break;
            case '[':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _LBRACK, s->lineno, _this);
                break;
            case ']':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col - 1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _RBRACK, s->lineno, _this);
                break;
            case '{':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _LBRACE, s->lineno, _this);
                break;
            case '}':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _RBRACE, s->lineno, _this);
                break;
            case ':':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _COLON, s->lineno, _this);
                break;
            case ';':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _SEMICOLON, s->lineno, _this);
                break;
            case ',':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _COMMA, s->lineno, _this);
                break;
            case '.':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _STOP, s->lineno, _this);
                break;
            case ' ':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _SPCE, s->lineno, _this);
                break;
            case '\n':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                s->lineno++;
                return 0;
            case EOF:
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                return EOF;
            default:
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STRING, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos);
                }
                printf("Unknown character '%c' at line %d\n", _this, s->lineno);
                break;
        }
        _col++;
    }
}

int scanner_all(scanner* s) {
    int _res;
    while(true){
        _res = scanner_nextline(s);
        if(_res == EOF){
            printf("File ended...");
            break;
        }
        if(_res == 1){
            fprintf(stderr, "An error occured during reading.");
            break;
        }
    }
    return _res;
}

