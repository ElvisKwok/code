/*
 * get current time and parse it by strftime as command date(1) shows
 */

#include "apue.h"
#include <time.h>

//int main(int argc, char *argv[])
//{
//	time_t now = time(NULL);
//	struct tm *now_tm = localtime(&now);
//	const int maxsize = 20;
//	char buf[maxsize];
//	char format[] = "%a %b %d %X %Z %Y";
//	strftime(buf, maxsize, format, now_tm);
//	printf("%s\n", buf);
//	exit(0);
//}

int main(void)
{
	const int 	maxsize = 20;
	time_t 		now;
	struct tm 	*now_tm;
	char 		buf[maxsize];
	char 		format[] = "%a %b %d %X %Z %Y";

	if ((now = time(NULL)) == -1)
		err_sys("time error");
	
	if ((now_tm = localtime(&now)) == NULL)
		err_sys("localtime error");

	if ((strftime(buf, maxsize, format, now_tm)) == -1) // should check by 0, but error arised??
		err_sys("strftime error");
	fputs(buf, stdout);
	exit(0);
}
