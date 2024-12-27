#include "Headers/VEST_ALL.h"
#include "Headers/VEST_INTERPRETED/VEST_BUILTIN.h"

#include <cstdio>

using namespace VEST;

int main() {
	VEST_CLASS test;
	test.$Constructor$ = []() {
		return 0;
	};
	printf("%d\n", test.$Constructor$());

	int (*ptr)();
	ptr = []() {
		return 1;
		};
	ptr();

	return 0;
}
