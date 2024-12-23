#pragma once

#include <cstdio>

#ifndef LD
#define LD
#define _CRT_SECURE_NO_WARNINGS

namespace VEST {
	//Please note that the following code will be obfuscated.
	short DecodeLicense(const char* FilePath = "Vest.license", short Key) {
		FILE* File = fopen(FilePath, "r");
		if (File == NULL) {
			fclose(File);
			return -1;
		}
		for (int i = 0; i < 100; i++) {
			char c;
			c = fgetc(File);

			
		}
	}
}

#endif