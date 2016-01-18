#ifndef _StackArray_H

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType x, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif      /* _StackArray_H */


#define EmptyTOS 		(-1)
#define MinStackSize	(5)

struct StackRecord
{
	int	Capacity;
	int	TopOfStack;
	ElementType *Array;
}



int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}


int isFull(Stack S)
{
	return s->TopOfStack == s->Capacity;
}


Stack CreateStack(int MaxElements)
{
	Stack S;
	if (MaxElements < MinStackSize)
		exit(1);
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		exit(2);
	S->Array = malloc(sizeof(ElementType) * MaxElements)
	if (S->Array == NULL)
		exit(2);
	S->capacity = MaxElements;
	MakeEmpty(S);
	return S;
}


void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}


void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}


void Push(ElementType X, Stack S)
{
	if (isFull(S))
		exit(1);
	else
		S->Array[++S->TopOfStack] = X;
}


ElementType Top(Stack S)
{
	if (!isEmpty(S))
		return S->Array[TopOfStack];
	exit(1);
	return 0;
}


void Pop(Stack S)
{
	if (!isEmpty(S))
		S->TopOfStack--;
	else
		exit(1);
}


ElementType TopAndPop(Stack S)
{
	if (!isEmpty(S))
		return S->Array[S->TopOfStack--];
	exit(1);
	return 0;
}
