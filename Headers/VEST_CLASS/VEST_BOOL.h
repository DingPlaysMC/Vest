#pragma once

#include <windows.h>
#include "VEST_DATA.h"

#ifndef VEST_BOOL_H
#define VEST_BOOL_H

class VEST_BOOL : VEST_DATA {
public:
	static const short DATA_TYPE = 0x04;
	bool Bool = false;

	void Update() override {
		DATA = &this->Bool;
		DATA_ADDR = &Bool;
	}
};

#endif