#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	//base case
	if (head == nullptr) {
		smaller = nullptr;
		larger = nullptr;
		return;
	}

	Node* next = head->next;
	if (head->val > pivot) {
		larger = head;
		llpivot(next, smaller, larger->next, pivot);
	}
	else { // head->val <= pivot
		smaller = head;
		llpivot(next, smaller->next, larger, pivot);
	}
	
	head = nullptr;
}