#pragma once

#include <windows.h>

#ifndef VEST_DATA_H
#define VEST_DATA_H

class VEST_DATA {
	public:
		bool AUTO_SYNC = true;
		void* DATA_ADDR = NULL;
		long long DATA_SIZE = 0;
		short DATA_TYPE = -0x1;
		void* DATA = NULL;

		void* Visit() {
			return DATA;
		}

		int GetSize() {
			return sizeof(DATA);
		}

		void Clear() {
			DATA = NULL;
		}

		virtual void Update() {}

		VEST_DATA(void* Data = NULL) {
			void* DATA_ADDR = NULL;
			long long DATA_SIZE = 0;
			short DATA_TYPE = -0x1;
			void* DATA = Data;
		}

};

class VEST_STREAM:VEST_DATA {
	public:
		static const short DATA_TYPE = 0x0003;
		HANDLE Stream;

		HANDLE InitStdin() {
			this->Stream=GetStdHandle((DWORD)-10);
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

class VEST_FILE :VEST_DATA {
	public:
		static const short DATA_TYPE = 0x0004;
		HANDLE File;
		
		HANDLE NewFileA(LPCSTR name) {
			this->File = CreateFileA(name, GENERIC_READ | GENERIC_WRITE, 0, NULL, 1, FILE_ATTRIBUTE_NORMAL, NULL);
			return this->File;
		}

		HANDLE ReadFileA(LPCSTR name) {
			this->File = CreateFileA(name, GENERIC_READ | GENERIC_WRITE, 0, NULL, 3, FILE_ATTRIBUTE_NORMAL, NULL);
			return this->File;
		}

		BOOL Close(HANDLE file) {
			return CloseHandle(file);
		}

		void Update() override {
			DATA = &this->File;
			DATA_ADDR = &File;
		}
};


class VEST_ERROR :VEST_DATA {
	public:
		short DATA_TYPE = 0x0005;
		int Error;

		void Update() override {
			DATA = &this->Error;
			DATA_ADDR = &Error;
		}
};

class VEST_THREAD :VEST_DATA {
	public:
		static const short DATA_TYPE = 0x0006;
		HANDLE Thread;

		void Update() override {
			DATA = &this->Thread;
			DATA_ADDR = &Thread;
		}
};

class VEST_STRING :VEST_DATA {
	public:
		static const short DATA_TYPE = 0x0007;
		char* String = new char[25536];
		short index = -1;

		void Append(VEST_STRING str) {
			for (int i = 0; i <= str.index; i++) {
				this->String[this->index] = str.String[i];
				index++;
			}
		}

		void Append(char* str) {
			for (int i = 0; i < strlen(str); i++) {
				this->String[this->index] = str[i];
				index++;
			}
		}

		VEST_STRING operator+(VEST_STRING str) {
			VEST_STRING newstr;
			newstr.Append(this->String);
			newstr.Append(str);
			return newstr;
		}

		short GetLen() {
			return this->index;
		}

		void Update() override {
			DATA = &this->String;
			DATA_ADDR = &String;
		}

};

class VEST_VOID :VEST_DATA {
	public:
		static const short DATA_TYPE = 0x0008;
		void* Void;

		void Update() override {
			DATA = &this->Void;
			DATA_ADDR = &Void;
	}
};


#endif