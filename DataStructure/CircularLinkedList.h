#pragma once
#include <iostream>
#include <stdlib.h>

typedef int Element;

typedef struct ListNode {
	Element Data;
	struct ListNode* Link;
}ListNode;

//함수 원형 선언
ListNode* Insert_First(ListNode *Head, Element Value);
ListNode* Insert_Last(ListNode* Head, Element Data);
ListNode* Insert(ListNode* Head, ListNode* Pre, Element Value);
ListNode* Delete_First(ListNode* Head);
ListNode* Delete(ListNode* Head, ListNode* Pre);
void Print_List(ListNode* Head);
void Display(ListNode* Head, int n, int k);