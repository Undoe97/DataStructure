#include <iostream>
using namespace std;

typedef int Element;

typedef struct LNode {
	Element Data;
	Node* PrevNode;
	Node* NextNode;
}Node;

class CDLLinkedList {
private:
	Node* Head;
	Node* Tail;
public:
	CDLinkedList() {// ������
		Head = NULL; //���� ���� ��� �η� �ʱ�ȭ
		Tail = NULL;
	}
	~CDLinkedList() {//�Ҹ���
		 while (Head != nullptr) { //��尡 ������Ʈ�϶�����
			 Node* DeleteTarget = Head;
			 Head = Head->NextNode;
			 delete DeleteTarget;
		 }
	}
	//��� ���� �Լ�
	Node* CreateNode(Element NewData) {
		 Node* NewNode = new Node;
		 NewNode->Data = NewData;
		 NewNode->PrevNode = NULL;
		 NewNode->NextNode = NULL;
		 return NewNode;
	}
	//��� �Ҹ�
	void DestroyNode(Node* Node) {
		 delete Node;
	}
	//��� �߰�
	void AppendNode(Node* NewNode) {
		//��� ��尡 ���̶�� ���� �߰��ϴ� ��尡 ��尡 �ȴ�
		if (Head == NULL) {
			Head = NewNode;
			Head->NextNode = Head;
			Head->PrevNode = Head;
		}
		else {
			//���ϰ� ��� ���̿� NewNode ����
			Tail = Head->PrevNode;
			Tail->NextNode->PrevNode = NewNode;
			Tail->NextNode = NewNode;

			NewNode->NextNode = Head;
			NewNode->PrevNode = Tail; //���ο� ������ PrevNode�� ������ ������ ����Ŵ
		}
	}

	void RemoveNode(Node* Remove) {
		if (Head == Remove){
			Head->PrevNode->NextNode = Remove->NextNode;
			Head->NextNode->PrevNode = Remove->PrevNode;

			Head = Remove->NextNode;

			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
		}
		else {
			Remove->PrevNode->NextNode = Remove->NextNode;
			Remove->NextNode->PrevNode = Remove->PrevNode;

			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
		}
	}

};

int main() 
{
	


	return 0;
}