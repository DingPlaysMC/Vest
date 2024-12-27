#pragma once

#include "VEST_DATA.h"

#ifndef	VEST_VOID_H
#define VEST_VOID_H

class VEST_VOID :VEST_DATA {
public:
	static const short DATA_TYPE = 0x0008;
	short Void = 0;

	void Update() override {
		DATA = &this->Void;
		DATA_ADDR = &Void;
	}
};

#endif