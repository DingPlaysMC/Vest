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
			return "UndefinedIdenfierError";

		case 0x0002:
			return "InvalidCharacterError";

		case 0x0003:
			return "InvalidIndexError";

		case 0x0004:
			return "DivideByZeroError";

		case 0x0005:
			return "UnableToConvertTypeError";

		case 0x0006:
			return "UnclosedBracketsError";

		case 0x0007:
			return "UnclosedStringError";

		case 0x0008:
			return "OverflowError";
		}
	}
};

#endif