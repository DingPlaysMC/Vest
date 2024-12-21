#include<windows.h>


#ifndef VEST_BUILTIN_H
#define VEST_BUILTIN_H

namespace VEST {
	LPCWSTR VAPI ANCIConvert(char* multi) {
		int index = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, multi, -1, NULL, 0);
		wchar_t* newwide = new wchar_t[index];
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, multi, -1, newwide, index);
		return newwide;
	}
}

#endif
