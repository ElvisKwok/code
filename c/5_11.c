/*
 *	using qsort2 with command line parameter.
 *	default sorting is in dictionary sequence.
 *  can be reinforced by option -n in numerical sorting.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "readlines_writelines.c"

#define MAXLINES 	5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void swap(void *v[], int i, int j);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);



int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort2((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
}


void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort2(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	if (left > right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);

	qsort2(v, left, last-1, comp);
	qsort2(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2)
{
	double f1, f2;
	f1 = atof(s1);
	f2 = atof(s2);
	if (f1 < f2)
		return -1;
	else if (f1 > f2)
		return 1;
	else
		return 0;
}
