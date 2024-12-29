#include "Headers/VEST_ALL.h"
#include "Headers/VEST_INTERPRETED/VEST_BUILTIN.h"

#include <cstdio>

using namespace VEST;

int main() {
	VEST_CLASS test;
	test.$Constructor$ = []() {
		printf("Constructor called\n");
	};
	test.$Constructor$();

	return 0;
}