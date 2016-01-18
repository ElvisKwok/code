#ifndef _HashSep_H

struct ListNode;
struct HashTbl;
typedef struct ListNode *Position;
typedef Position List;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
//void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
//ElementType Retrieve(Position P);

#endif

struct ListNode
{
    ElementType Element;
    Position    Next;
}

struct HashTbl
{
    int TableSize;
    List *TheLists;
}

#define MinTableSize 5

bool isPrime(int n)
{
    int i;
    for (i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// return the first prime large than n
int NextPrime(int n)
{
    int i;
    for (i = n; ; i++) {
        if (isPrime(i))
            break;
    }
    return i;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MinTableSize) {
        Error("Table size too small");
        return NULL;
    }

    // Allocate table
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space");
    H->TableSize = NextPrime(TableSize);

    // Allocate array of lists
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        FatalError("Out of space");

    // Allocate list headers
    for (int i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key)  // probably need strcmp
        P = P->Next;
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;
    Pos = Find(Key, H);
    if (Pos == NULL) {        // Key is not found, Insert it.
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("Out of space");
        else {
            L = H->TheLists[Has(Key, H->TableSize)];
            NewCell->Element = Key;
            NewCell->Next = L->Next;
            L->Next = NewCell;
        }
    }
}
