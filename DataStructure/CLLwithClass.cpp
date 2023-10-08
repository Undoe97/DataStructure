#include <iostream>
#include "CLLwithClass.h"
using namespace std;

//노드 처음 삽입
ListNode* Insert_First(ListNode* Head, Element Data) {
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->Data = Data;
	if (Head == NULL) {
		Head = Node;
		Node->Link = Head;
	}
	else {
		Node->Link = Head->Link;
		Head->Link = Node;
	}
	return Head; // 변경된 헤드 포인터 반환
}
//노드 끝에 삽입
ListNode* Insert_Last(ListNode* Head, Element Data) {
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->Data = Data;
	if (Head == NULL) {
		Head = Node;
		Node->Link = Head;
	}
	else {
		Node->Link = Head->Link;
		Head->Link = Node;
		Head = Node;
	}
	return Head; // 변경된 헤드 포인터 반환
}
ListNode* Insert(ListNode* Head, ListNode* Pre, Element Value) {
	ListNode* P = (ListNode*)malloc(sizeof(ListNode));
	P->Data = Value;
	P->Link = Pre->Link;
	Pre->Link = P;
	return Head;
}
ListNode* Delete_First(ListNode* Head) {
	ListNode* Removed;
	if (Head == NULL) return NULL;
	Removed = Head;
	Head = Removed->Link;
	free(Removed);
	return Head;
}
ListNode* Delete(ListNode* Head, ListNode* Pre) {
	ListNode* Removed;
	Removed = Pre->Link;
	Pre->Link = Removed->Link;
	if (Removed == Head->Link) {
		Head->Link = Removed->Link;
	}
	cout << Removed->Data;
	free(Removed);
	return Head;
}
//요세푸스 문제 푸는법
void Display(ListNode* Head, int n, int k)
{
	ListNode* p;
	int i, j;
	if (Head == NULL)return;
	p = Head;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < k - 1; i++)
		{
			p = p->Link;
		}
		Delete(Head, p);
		if (j != n - 1)
			printf(",");
		if (j != n - 1)
			printf(" ");
	}
}
//리스트 출력 함수
void Print_List(ListNode* Head) {
	for (ListNode* P = Head; P != NULL; P = P->Link) {
		cout << P->Data << "->";
	}
	cout << "NULL\n";

}