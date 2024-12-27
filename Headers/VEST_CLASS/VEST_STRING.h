#pragma once

#include "VEST_DATA.h"

#ifndef VEST_STRING_H
#define VEST_STRING_H

#include "VEST_DATA.h"
#include <string>

class VEST_STRING :VEST_DATA {
public:
	static const short DATA_TYPE = 0x03;
	std::string String;

	void Update() override {
		DATA = &this->String;
		DATA_ADDR = &String;
	}

	std::string Getter() {
		return String;
	}

	void Setter(std::string Data) {
		String = Data;
	}

	void Setter(const char* Data) {
		String = std::string(Data);
	}

	void Setter(VEST_STRING Data) {
		String = Data.String;
	}


	template<typename T>
	void operator=(std::string Const) {
		this->Setter(Const);
	}

	VEST_STRING operator+(VEST_STRING Data) {
		VEST_STRING Ret;
		Ret = this->String.append(Data.String);
		return Ret;
	}

	size_t Find(const char* SubStr) {
		return this->String.find(SubStr);
	}

	char& operator[](long long Index) {
		return this->String[Index];
	}

	template<typename T>
	VEST_STRING(T Data) {
		this->Setter(Data);
	}

	VEST_STRING() {
		char* Str = new char[1];
		Str[0] = '\0';
		this->Setter(Str);
	}
};

#endif