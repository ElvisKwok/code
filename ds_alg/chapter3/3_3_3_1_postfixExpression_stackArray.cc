#include <iostream>
#include <string>
using namespace std;

/*
 * expression is splited by ' '
 * operand:		
 * operator:	+, -, *, /
 */

template <typename ElementType>
class Stack {
public:
	Stack(int MaxElements=20);
	~Stack();
	int IsEmpty();
	int IsFull();
	void MakeEmpty();
	void Push(ElementType x);
	ElementType Top();
	void Pop();
	ElementType TopAndPop();
	int Size() {return TopOfStack+1;}
private:
	int EmptyTOS;
	//const int MinStackSize;
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

template <typename ElementType>
Stack<ElementType>::Stack(int MaxElements)
{
	EmptyTOS = -1;
	Capacity = MaxElements;
	TopOfStack = EmptyTOS;
	Array = new ElementType[Capacity];
}	

template <typename ElementType>
Stack<ElementType>::~Stack()
{
	delete [] Array;
}

template <typename ElementType>
int Stack<ElementType>::IsEmpty()
{
	return TopOfStack == EmptyTOS;
}

template <typename ElementType>
int Stack<ElementType>::IsFull()
{
	return TopOfStack == Capacity;
}

template <typename ElementType>
void Stack<ElementType>::MakeEmpty()
{
	TopOfStack = EmptyTOS;
}

template <typename ElementType>
void Stack<ElementType>::Push(ElementType x)
{
	if (IsFull()) {
		cout << "Error: Full to push" << endl;
		return;
	}
	Array[++TopOfStack] = x;
}

template <typename ElementType>
ElementType Stack<ElementType>::Top()
{
	return Array[TopOfStack];
}

template <typename ElementType>
void Stack<ElementType>::Pop()
{
	if (IsEmpty()) {
		cout << "Error: Empty to pop" << endl;
		return;
	}
	TopOfStack--;
}

template <typename ElementType>
ElementType Stack<ElementType>::TopAndPop()
{
	if (!IsEmpty()) {
		return Array[TopOfStack--];
	}
	else {
		cout << "Error: Empty to pop" << endl;
		return 0;
	}
}

// should check if S.capacity >= 2. Ignore for simplicity.
template <typename ElementType>
void stackAdd(Stack<ElementType> &S) {	// Must reference to S
	ElementType tmp1, tmp2;
	tmp1 = S.TopAndPop();
	tmp2 = S.TopAndPop();
	tmp2 += tmp1;
	S.Push(tmp2);
}

template <typename ElementType>
void stackSubstraction(Stack<ElementType> &S) {
	ElementType tmp1, tmp2;
	tmp1 = S.TopAndPop();
	tmp2 = S.TopAndPop();
	tmp2 -= tmp1;
	S.Push(tmp2);
}

template <typename ElementType>
void stackMultiplication(Stack<ElementType> &S) {
	ElementType tmp1, tmp2;
	tmp1 = S.TopAndPop();
	tmp2 = S.TopAndPop();
	tmp2 *= tmp1;
	S.Push(tmp2);
}


template <typename ElementType>
void stackDivision(Stack<ElementType> &S) {
	ElementType tmp1, tmp2;
	tmp1 = S.TopAndPop();
	tmp2 = S.TopAndPop();
	tmp2 /= tmp1;
	S.Push(tmp2);
}

template <typename ElementType>
void compute(Stack<ElementType> &S, string str)
{
	ElementType tmp = 0, x = 0, y = 0;	// float_num = x.y, int_num = x
	for (int i = 0; i < str.size(); ++i) {
		switch (str[i]) {
			case '+':
				stackAdd(S);
				break;
			case '-':
				stackSubstraction(S);
				break;
			case '*':
				stackMultiplication(S);
				break;
			case '/':
				stackDivision(S);
				break;
			case ' ':	// push element x to stack while space ' ' is met
				if (str[i-1] >= '0' && str[i] <= '9')	// Do not put the old x after a computatio of "+-*/"
					S.Push(x);
				x = 0;
				y = 0;
				break;
			case '.':	// float
				tmp = 10.0;
				while (str[i+1] != ' ') {
					i++;
					if (str[i] >= '0' && str[i] <= '9') {
						y += (str[i] - '0') / tmp;
						tmp *= 10;
					}
				}
				x += y;
				break;
			default:	// char_digit to num
				if (str[i] >= '0' && str[i] <= '9')
					x = x * 10 + str[i] - '0';
		}
	}
	if (S.Size()==1)
		cout << str << " = " << S.Top() << endl;
}

// postfix do not store bracket "(, )".
// stack czf only store operator "+-*/".
// left associativity: operand associate with the left (same)operator first.(FIFO)
// just for int data.
void infixToPostfix(string &infix, string &postfix, int &m)	// m to track the len of postfix
{
	int len = infix.size();	
	Stack<char> czf;
	for (int i = 0; i < len; ++i) {
		if (infix[i] >= '0' && infix[i] <= '9') {		// num is print directly
			postfix[m++] = infix[i];
			postfix[m++] = ' ';
		}
		if (infix[i] == '(')
			czf.Push(infix[i]);
		if (infix[i] == '+'){	// compare priority of '+' with stack czf's top
			if (!czf.IsEmpty() && (czf.Top()=='*'||czf.Top()=='/'||czf.Top()=='+')) {	// if top is prior and equal(left associativity, FIFO)
				postfix[m++] = czf.TopAndPop();
				postfix[m++] = ' ';
				czf.Push(infix[i]);
			}
			else	// if top is inferior.
				czf.Push(infix[i]);
		}
		if (infix[i] == '-'){	// compare priority of '-' with stack czf's top
			if (!czf.IsEmpty() && (czf.Top()=='*'||czf.Top()=='/'||czf.Top()=='-')) {	// 1-2-3 should return 12-3- not 123--
				postfix[m++] = czf.TopAndPop();
				postfix[m++] = ' ';
				czf.Push(infix[i]);
			}
			else
				czf.Push(infix[i]);
		}
		if (infix[i] == '*')		// Push directly
			czf.Push(infix[i]);
		if (infix[i] == '/') {
			if (!czf.IsEmpty() && czf.Top()=='/') {	// 1/2/3 should return 12/3/ not 123//
				postfix[m++] = czf.TopAndPop();
				postfix[m++] = ' ';
				czf.Push(infix[i]);
			}
			else
				czf.Push(infix[i]);
		}
		if (infix[i] == ')') {	// pop until '(' is met
			while (czf.Top() != '(') {
				postfix[m++] = czf.TopAndPop();
				postfix[m++] = ' ';
			}
			czf.Pop();		// Pop '('
		}
	}
	while (!czf.IsEmpty()) {
		postfix[m++] = czf.TopAndPop();
		postfix[m++] = ' ';
	}
}

int main()
{
	Stack<int> S_int(10);
	compute<int>(S_int, "6 5 2 3 + 8 * + 3 + *");
	Stack<double> S_double(10);
	compute<double>(S_double, "2 3 * 1.5 -");

	//string infix = "6*((5+(2+3)*8)+3)", postfix(2*infix.size(), '0');
	//int m = 0;
	//infixToPostfix(infix, postfix, m);
	//postfix = postfix.substr(0, m-1);
	//cout << postfix << endl;
	string infix = "1/2/3", postfix(2*infix.size(), '0');
	int m = 0;
	infixToPostfix(infix, postfix, m);
	postfix = postfix.substr(0, m-1);
	cout << postfix << endl;

	return 0;
}
