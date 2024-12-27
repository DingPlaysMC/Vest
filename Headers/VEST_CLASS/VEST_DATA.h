#pragma once

#include "VEST_CLASS.h"

#ifndef VEST_DATA_H
#define VEST_DATA_H

class VEST_DATA : VEST_CLASS {
	public:
		bool AUTO_SYNC = true;
		void* DATA_ADDR = NULL;
		short DATA_TYPE = 0x00;
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

#endif
