#pragma once

#include "lexer_global.hpp"

typedef struct{
    char* str;
    int startcol;
    int endcol;
}strpos;

inline bool _isletter(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


char* _convert_char(const char* filename, char** buffer) {
    FILE* file = fopen(filename, "rb"); 
    if (file == NULL) {
        printf("Error opening file.\n", filename);
        return NULL;
    }
    
    fseek(file, 0, SEEK_END); 
    long file_size = ftell(file); 
    rewind(file); 

    *buffer = (char*)malloc(file_size + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    
    size_t bytes_read = fread(*buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        fprintf(stderr, "Can't fully read the document.\n");
        free(*buffer);
        fclose(file);
        return NULL;
    }
    
    (*buffer)[file_size] = '\0';

    fclose(file);
}


int _sgetc(char** ptr) {
    if (ptr == NULL || *ptr == NULL) {
        return EOF;  
    }
    
    int ch = (unsigned char)**ptr;
    if (ch == '\0') {
        return EOF;  
    }
    
    (*ptr)++;  
    return ch;
}


scanner* scanner_init(const char* filename) {
    scanner* s = (scanner*)malloc(sizeof(scanner));
    _convert_char(filename, &(s->pFile));
    if (!s) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    s->lineno = 1;
    return s;
}


void scanner_destroy(scanner* s) {
    if (s) free(s);
}


int scanner_nextline(scanner* s) {
    if (!s->pFile) return 1;
    char _this;
    bool _retainflg = false;
    int _col = 1;
    strpos* _pos;

    while(_this = (char)_sgetc(&(s->pFile))) {
        switch(_this){
            case '\'':
                if (_retainflg) {
                    _retainflg = false;
                    _pos->endcol = _col - 1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", 
                        _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                {
                    
                    _pos = (strpos*)malloc(sizeof(strpos));
                    if (!_pos) {
                        fprintf(stderr, "Memory allocation failed.\n");
                        return 1;
                    }
                    _pos->str = (char*)malloc(101);
                    if (!_pos->str) {
                        fprintf(stderr, "Memory allocation failed.\n");
                        free(_pos);
                        return 1;
                    }
                    memset(_pos->str, 0, 101);
                    _pos->startcol = _col;
                    int index = 0;
                    
                    
                    _pos->str[index++] = _this;
                    
                    int ch;
                    while ((ch = _sgetc(&(s->pFile)))) {
                        _col++;  
                        if (ch == EOF || ch == '\n') {
                            
                            fprintf(stderr, "Error: Can't close the string at line %d, column %d\n", 
                                    s->lineno, _col);
                            free(_pos->str);
                            free(_pos);
                            if (ch == '\n') s->lineno++;
                            return 1;
                        }
                        
                        if (index < 100) {
                            _pos->str[index++] = (char)ch;
                        } else {
                            fprintf(stderr, "String too long at line %d\n", s->lineno);
                            free(_pos->str);
                            free(_pos);
                            return 1;
                        }
                        
                        if (ch == '\'') {
                            _pos->endcol = _col;
                            break;
                        }
                    }
                    
                    _pos->str[index] = '\0';  
                    printf("Token %d(line %d, from column %d to %d): %s\n", 
                        _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                break;
            
            case '"':
                if (_retainflg) {
                    _retainflg = false;
                    _pos->endcol = _col - 1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", 
                        _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                {
                    
                    _pos = (strpos*)malloc(sizeof(strpos));
                    if (!_pos) {
                        fprintf(stderr, "Memory allocation failed.\n");
                        return 1;
                    }
                    _pos->str = (char*)malloc(101);
                    if (!_pos->str) {
                        fprintf(stderr, "Memory allocation failed.\n");
                        free(_pos);
                        return 1;
                    }
                    memset(_pos->str, 0, 101);
                    _pos->startcol = _col;
                    int index = 0;
                    
                    
                    _pos->str[index++] = _this;
                    
                    int ch;
                    while ((ch = _sgetc(&(s->pFile)))) {
                        _col++;  
                        if (ch == EOF || ch == '\n') {
                            
                            fprintf(stderr, "Error: Can't close the string at line %d, column %d\n", 
                                    s->lineno, _col);
                            free(_pos->str);
                            free(_pos);
                            if (ch == '\n') s->lineno++;
                            return 1;
                        }
                        
                        if (index < 100) {
                            _pos->str[index++] = (char)ch;
                        } else {
                            fprintf(stderr, "String too long at line %d\n", s->lineno);
                            free(_pos->str);
                            free(_pos);
                            return 1;
                        }
                        
                        if (ch == '"') {
                            _pos->endcol = _col;
                            break;
                        }
                    }
                    
                    _pos->str[index] = '\0';  
                    printf("Token %d(line %d, from column %d to %d): %s\n", 
                        _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
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
                    _pos->str = (char*)malloc(101);
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
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _LBRACK, s->lineno, _this);
                break;
            
            case ']':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col - 1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _RBRACK, s->lineno, _this);
                break;

            case '{':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _LBRACE, s->lineno, _this);
                break;

            case '}':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _RBRACE, s->lineno, _this);
                break;

            case ':':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _COLON, s->lineno, _this);
                break;

            case ';':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _SEMICOLON, s->lineno, _this);
                break;

            case ',':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _COMMA, s->lineno, _this);
                break;

            case '.':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _STOP, s->lineno, _this);
                break;
            
            case '0'...'9':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _NUM, s->lineno, _this);
                break;

            
            case ' ':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                printf("Token %d(line %d): %c\n", _SPCE, s->lineno, _this);
                break;

            case '\n':
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                s->lineno++;
                return 0;

            case EOF:
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
                    free(_pos);
                }
                return EOF;

            default:
                if(_retainflg){
                    _retainflg = false;
                    _pos->endcol = _col-1;
                    printf("Token %d(line %d, from column %d to %d): %s\n", _STR, s->lineno, _pos->startcol, _pos->endcol, _pos->str);
                    free(_pos->str);
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

