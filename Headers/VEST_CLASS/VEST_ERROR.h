#pragma once

#include <windows.h>
#include "VEST_DATA.h"

#ifndef VEST_ERROR_H
#define VEST_ERROR_H

class VEST_ERROR :VEST_DATA {
public:
	short DATA_TYPE = 0x0005;
	int ErrorCode;

	void Update() override {
		DATA = &this->ErrorCode;
		DATA_ADDR = &ErrorCode;
	}
};

#endif