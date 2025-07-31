#pragma once

#include <string>
#include <map>

#include "lexer_global.hpp"

std::map<std::string, keyword> create_tsmap() {
    std::map<std::string, keyword> m;
    m["int"] = _INT;
    return m;
}
std::map<std::string, keyword> tsmap = create_tsmap();

// Place to define the C++ functions
namespace{
    keyword get_token_type(const std::string& str){
        std::map<std::string, keyword>::iterator it = tsmap.find(str);
        if (it != tsmap.end()) {
            return it->second;
        }
        return _UNKNOWN;
    }
}

keyword wget_token_type(char* str){
    return get_token_type(std::string(str));
}