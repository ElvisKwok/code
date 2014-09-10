#include <string.h>

int strend(char *s, char *t)
{
	int diff = strlen(s) - strlen(t);
	if (diff < 0)
		return 0;
	s += diff;
	while (*s == *t) {
		s++;
		t++;
	}
	if (*s == '\0')
		return 1;
	else return 0;
}
