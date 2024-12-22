#pragma once

#include <windows.h>
#include "VEST_DATA.h"s

#ifndef VEST_STRING_H
#define VEST_STRING_H


class VEST_STRING :VEST_DATA {
public:
	static const short DATA_TYPE = 0x03;
	char* String = new char[25536];
	short index = -1;

	void Append(VEST_STRING str) {
		for (int i = 0; i <= str.index; i++) {
			this->String[this->index] = str.String[i];
			index++;
		}
	}

	void Append(char* str) {
		for (int i = 0; i < strlen(str); i++) {
			this->String[this->index] = str[i];
			index++;
		}
	}

	VEST_STRING operator+(VEST_STRING str) {
		VEST_STRING newstr;
		newstr.Append(this->String);
		newstr.Append(str);
		return newstr;
	}

	short GetLen() {
		return this->index;
	}

	void Update() override {
		DATA = &this->String;
		DATA_ADDR = &String;
	}

};

#endif