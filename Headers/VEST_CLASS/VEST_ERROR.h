#pragma once

#include <windows.h>
#include "VEST_DATA.h"

#ifndef VEST_ERROR_H
#define VEST_ERROR_H

#include "VEST_STRING.h"

class VEST_ERROR :VEST_DATA {
public:
	short DATA_TYPE = 0x05;
	int ErrorCode;

	void Update() override {
		DATA = &this->ErrorCode;
		DATA_ADDR = &ErrorCode;
	}

	VEST_ERROR(int ErrorCode) {
		this->ErrorCode = ErrorCode;
	}

	VEST_STRING GetErrorString() {
		switch (ErrorCode) {
		case 0x0001:
			return VEST_STRING("UndefinedIdenfierError");

		case 0x0002:
			return VEST_STRING("InvalidCharacterError");

		case 0x0003:
			return VEST_STRING("InvalidIndexError");

		case 0x0004:
			return VEST_STRING("DivideByZeroError");

		case 0x0005:
			return VEST_STRING("UnableToConvertTypeError");

		case 0x0006:
			return VEST_STRING("UnclosedBracketsError");

		case 0x0007:
			return VEST_STRING("UnclosedStringError");

		case 0x0008:
			return VEST_STRING("OverflowError");
		}
	}

	
};

#endif