#pragma once

#include "VEST_DATA.h"

#ifndef VEST_THREAD_H
#define VEST_THREAD_H

class VEST_THREAD : VEST_DATA {
public:
	static const short DATA_TYPE = 0x06;
	HANDLE Thread;

	void Update() override {
		DATA = this->Thread;
		DATA_ADDR = &Thread;
	}

};

#endif