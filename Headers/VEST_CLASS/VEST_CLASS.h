#pragma once

#include <windows.h>
#include <functional>

#ifndef VEST_CLASS_H
#define VEST_CLASS_H

class VEST_CLASS {
public:
	std::function<void()> $Constructor$;

	BYTE $Name$[256];
};

#endif