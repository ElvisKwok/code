#include <stdio.h>

#define MAXVAL	100			/* largest depth of stack val */

int sp = 0;					/* next empty space of stack */
int val[MAXVAL];			/* the stack of value		*/

void push(int);
int pop(void);
void print_top(void);
void print_stack();
int swap_top(void);
void clear_stack(void);

int main()
{
	int choice, i=0;
	while (1) {
		printf("push[1], pop[2], print_top[3], swap_top[4], clear_stack[5], print_stack[6]: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			push(i++);
			break;
		case 2:
			pop();
			break;
		case 3:
			print_top();
			break;
		case 4:
			swap_top();
			break;
		case 5:
			clear_stack();
			break;
		default:
			print_stack();
			break;
		}
	}
    return 0;
}

void push(int f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %d\n", f);
}

int pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0;
	}
}

void print_top(void)
{
	if (sp > 0)
		printf("%d\n", val[sp-1]);
	else {
		printf("error: stack empty\n");
	}
}

void print_stack()
{
	int i;
	for(i = 0; i < sp; i++){
		printf("%d ", val[i]);
	}
	printf("\n");
}

int swap_top(void)
{
	if (sp == 1)
	{
		printf("error: only one element\n");
		return -1;
	}
	int first_pop, second_pop;
	first_pop = pop();
	second_pop = pop();
	push(first_pop);
	push(second_pop);
	return 0;
}

void clear_stack(void)
{
	while(sp > 0)
		val[sp--] = 0;
}
