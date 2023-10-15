#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
} NODE;

typedef struct list {
	int size;
	NODE* head;
	NODE* rear;
} LIST;

void insert(LIST* pList, int data);
void pop(LIST* pList);
void moveLeft(LIST* pList);
void moveRight(LIST* pList);
int count_Left(LIST* pList, int data);
int count_Right(LIST* pList, int data);
void destroy(LIST* pList);

int main() {
	int n, ans = 0, m, i, find;
	scanf_s("%d %d", &n, &m);

	LIST* l = (LIST*)malloc(sizeof(LIST));
	l->head = l->rear = NULL;
	l->size = 0;

	for (i = 1; i <= n; i++) {
		insert(l, i);
	}
	for (i = 0; i < m; i++) {
		scanf_s("%d", &find);
		//printf("%d %d %d", find, count_fun2(l, find), count_fun3(l, find));
		if (count_Left(l, find) <= count_Right(l, find)) {
			while (l->head->data != find) {
				moveLeft(l);
				ans++;
			}
			pop(l);
		}


		else {
			while (l->head->data != find) {
				moveRight(l);
				ans++;
			}
			pop(l);
		}
		//printf(" > %d\n", ans);
	}
	printf("%d", ans);
	destroy(l);

	return 0;
}
// 삽입 함수
void insert(LIST* pList, int data) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	if (!pList->head) {
		pList->head = newNode;
		pList->head->next = newNode;
		pList->head->prev = newNode;
		pList->rear = pList->head;
	}
	else {
		newNode->prev = pList->rear;
		pList->rear->next = newNode;
		pList->rear = newNode;
		pList->head->prev = pList->rear;
		pList->rear->next = pList->head;
	}
	pList->size++;
}
// 삭제 함수
void destroy(LIST* pList) {
	NODE* deleteNode = pList->head;
	while (!pList->head) {
		pList->head = pList->head->next;
		free(deleteNode);
	}
	free(pList);
}
// 추출 함수
void pop(LIST* pList) {
	NODE* deleteNode = pList->head;
	pList->head = pList->head->next;
	pList->rear->next = pList->head;
	pList->head->prev = pList->rear;
	free(deleteNode);
}
//왼쪽으로 큐 이동
void moveLeft(LIST* pList) {
	pList->rear = pList->head;
	pList->head = pList->head->next;
}
//오른쪽으로 큐 이동
void moveRight(LIST* pList) {
	pList->head = pList->rear;
	pList->rear = pList->rear->prev;
}
//왼쪽 거리 세기
int count_Left(LIST* pList, int data) {
	NODE* curNode = pList->head;
	int count = 0;
	while (data != curNode->data) {
		count++;
		curNode = curNode->next;
	}
	return count;
}
//오른쪽 거리 세기
int count_Right(LIST* pList, int data) {
	NODE* curNode = pList->rear;
	int count = 1;
	while (data != curNode->data) {
		count++;
		curNode = curNode->prev;
	}
	return count;
}