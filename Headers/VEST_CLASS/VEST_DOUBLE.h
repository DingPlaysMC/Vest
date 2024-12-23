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

	void operator= (long double Const) {
		this->Setter(Const);
	}
};

#endif