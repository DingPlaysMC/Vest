#pragma once

#include <windows.h>
#include "VEST_DATA.h"

#ifndef VEST_DOUBLE_H
#define VEST_DOUBLE_H

class VEST_DOUBLE : VEST_DATA {
public:
	static const short DATA_TYPE = 0x0002;
	long double Double;

	void Update() override {
		DATA = &this->Double;
		DATA_ADDR = &Double;
	}
};

#endif