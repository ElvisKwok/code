#include <stdio.h>
#include <time.h>

int main()
{
	time_t start, end;
	time(&start);
	sleep(60);			/* sleep for 60s */
	time(&end);
	printf("time elapses %f sec(s)\n", difftime(end, start));
	return 0;
}
