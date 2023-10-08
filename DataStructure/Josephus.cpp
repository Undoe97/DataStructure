#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	ListNode* Head = NULL;
	for (int i = 1; i <= N; i++) {
		Head = Insert_Last(Head, i);

	}
	cout << "<";
	Display(Head, N, K);
	cout << ">";
	
	return 0;
}