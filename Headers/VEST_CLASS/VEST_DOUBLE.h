#pragma once

#include <windows.h>
#include "VEST_DATA.h"

#ifndef VEST_DOUBLE_H
#define VEST_DOUBLE_H

class VEST_DOUBLE : VEST_DATA {
public:
	static const short DATA_TYPE = 0x02;
	long double Double;

	void Update() override {
		DATA = &this->Double;
		DATA_ADDR = &Double;
	}

	long double Getter() {
		return Double;
	}

	void Setter(long double Data) {
		Double = Data;
	}

	void Setter(long long Data) {
		Double = (long double)Data;
	}

	void operator= (long double Const) {
		this->Setter(Const);
	}

	void operator= (long long Const) {
		this->Setter(Const);
	}

	template<typename T>
	VEST_DOUBLE(T Data) {
		this->Setter(Data);
	}

	VEST_DOUBLE() {
		this->Setter(long double(0.0));
	}
};

#endif