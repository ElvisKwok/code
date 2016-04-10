#include <stdio.h>
#include <stdlib.h>

int crash() {
	char *str = "crash!!!";
	str[1] = 'D';	// write .rodata
	return 2;
}

int foo() {
	return crash();
}

int main() {
	sleep(10);
	return foo();
}
