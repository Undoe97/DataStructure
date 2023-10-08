#include <iostream>
#include "CLLwithClass.h"
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	ListNode* List = NULL;
	for (int i = 1; i <= N; i++) {
		List = Insert_Last(List, i);

	}
	cout << "<";
	Display(List, N, K);
	cout << ">";

	return 0;

}