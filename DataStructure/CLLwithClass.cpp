#include <iostream>
#include "CLLwithClass.h"
using namespace std;

//��� ó�� ����
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
	return Head; // ����� ��� ������ ��ȯ
}
//��� ���� ����
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
	return Head; // ����� ��� ������ ��ȯ
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
//�似Ǫ�� ���� Ǫ�¹�
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
//����Ʈ ��� �Լ�
void Print_List(ListNode* Head) {
	for (ListNode* P = Head; P != NULL; P = P->Link) {
		cout << P->Data << "->";
	}
	cout << "NULL\n";

}