#include <iostream>
#include <stack>
#include <exception>
using namespace std;

// file description:
// using two stacks to implement two function of a queue
// appendTail(), deleteHead

template <typename T>
class CQueue {
public:
    CQueue();
    ~CQueue();

    void appendTail(const T& element);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue() {}

template <typename T>
CQueue<T>::~CQueue() {}

template <typename T>
void CQueue<T>::appendTail(const T& element) {
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead() {
    if (stack2.empty()) {
        while(!stack1.empty()) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.empty())
        throw new exception();
    T& head = stack2.top();
    stack2.pop();
    return head;
}

// =====================Test Code=====================
void test(char actual, char expected) {
    if (actual == expected)
        cout << "test passed." << endl;
    else
        cout << "test failed." << endl;
}

int main() {
    CQueue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    test(head, 'a');

    head = queue.deleteHead();
    test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    test(head, 'd');

    head = queue.deleteHead();
    test(head, 'e');

    return 0;
}
