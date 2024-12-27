#pragma once

#include <windows.h>
#include <any>

#ifndef VEST_CLASS_H
#define VEST_CLASS_H

class VEST_CLASS {
public:
	
	DWORD(*$Constructor$)(DWORD Args...);
	WORD(*$Constructor$)(WORD Args...);
	BYTE(*$Constructor$)(BYTE Args...);

	BYTE $Name$[256];

};

#endif