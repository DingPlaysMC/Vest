#pragma once

#include <windows.h>

#ifndef VEST_STREAM_H
#define VEST_STREAM_H

class VEST_STREAM :VEST_DATA {
public:
	static const short DATA_TYPE = 0x07;
	HANDLE Stream;

	HANDLE InitStdin() {
		this->Stream = GetStdHandle((DWORD)-10);
		return this->Stream;
	}

	HANDLE InitStdout() {
		this->Stream = GetStdHandle((DWORD)-11);
		return this->Stream;
	}

	HANDLE InitStderr() {
		this->Stream = GetStdHandle((DWORD)-12);
		return this->Stream;
	}

	HANDLE InitCostom(HANDLE stream) {
		this->Stream = stream;
		return stream;
	}

	BOOL Write(LPCVOID buffer, DWORD size) {
		return WriteFile(this->Stream, buffer, size, NULL, NULL);
	}

	BOOL Read(LPVOID buffer, DWORD size) {
		return ReadFile(this->Stream, buffer, size, NULL, NULL);
	}

	void Update() override {
		DATA = &Stream;
		DATA_ADDR = &Stream;
	}
};

#endif