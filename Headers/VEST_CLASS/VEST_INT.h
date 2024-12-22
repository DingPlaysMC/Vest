#pragma once

#include <windows.h>
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

	void Setter(int Data) {
		Int = Data;
	}

	void operator=(int Const) {
		this->Setter(Const);
	}
};

#endif