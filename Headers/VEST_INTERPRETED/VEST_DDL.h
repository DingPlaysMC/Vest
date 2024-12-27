#pragma once

// DDL repersents "Dymanic Data List"

#include "../VEST_CLASS/VEST_ALL_TYPE.h"

#ifndef VEST_DDL_H
#define VEST_DDL_H

class VEST_DDL {
public:
	VEST_CLASS* DataList[65536];
	unsigned short Index;
	
};

#endif