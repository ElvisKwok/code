#ifndef _Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType x, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif      /* _Queue_H */


#define MinQueueQize	(5)

struct QueueRecord
{
	int	Capacity;
	int Front;
	int Rear;
	int	Size;
	ElementType *Array;
}



int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}


int isFull(Queue Q)
{
	return s->Size == s->Capacity;
}


Queue CreateQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements < MinQueueQize)
		exit(1);
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		exit(2);
	Q->Array = malloc(sizeof(ElementType) * MaxElements)
	if (Q->Array == NULL)
		exit(2);
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
	return Q;
}


void DisposeQueue(Queue Q)
{
	if (Q != NULL) {
		free(Q->Array);
		free(Q);
	}
}


void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}



void Enqueue(ElementType X, Queue Q)
{
	if (isFull(Q))
		exit(1);
	else {
		Q->Size++;
		Q->Rear = (Q->Rear++) % Q->Capacity;
		Q->Array[Q->Rear] = X;
	}
}


ElementType Front(Queue Q)
{
	if (!isEmpty(Q))
		return Q->Array[Front];
	exit(1);
	return 0;
}


void Dequeue(Queue Q)
{
	if (!isEmpty(Q))
		Q->Front = (Q->Front++) % Q->Capacity;
	else
		exit(1);
}


ElementType FrontAndDequeue(Queue Q)
{
	if (!isEmpty(Q))
		return Q->Array[(Q->Front++)%Q->Capacity];
	exit(1);
	return 0;
}
