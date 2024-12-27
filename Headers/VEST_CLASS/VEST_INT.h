#pragma once

#include "VEST_DATA.h"

#ifndef VEST_INT_H
#define VEST_INT_H

class VEST_INT : VEST_DATA {
public:
	static const short DATA_TYPE = 0x01;
	long long Int = 0;

	void Update() override {
		DATA = &this->Int;
		DATA_ADDR = &Int;
	}

	long long Getter() {
		return Int;
	}

	void Setter(long long Data) {
		Int = Data;
	}

	void Setter(long double Data) {
		Int = (long long)Data;
	}

	void operator=(long long Const) {
		this->Setter(Const);
	}

	void operator=(long double Const) {
		this->Setter(Const);
	}

	template<typename T>
	VEST_INT(T Data) {
		this->Setter(Data);
	}

	VEST_INT() {
		this->Setter(long long(0));
	}
};

#endif