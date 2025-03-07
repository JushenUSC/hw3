#include "stack.h" 
#include <iostream>
using namespace std;

int main() {
	Stack<int> myStack;
	cout << "Empty right now: " << myStack.empty() << endl;
	myStack.push(9);
	cout << "Empty right now: " << myStack.empty() << endl;
}