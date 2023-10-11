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
	CDLinkedList() {// 생성자
		Head = NULL; //헤드와 테일 노드 널로 초기화
		Tail = NULL;
	}
	~CDLinkedList() {//소멸자
		 while (Head != nullptr) { //헤드가 널포인트일때까지
			 Node* DeleteTarget = Head;
			 Head = Head->NextNode;
			 delete DeleteTarget;
		 }
	}
	//노드 생성 함수
	Node* CreateNode(Element NewData) {
		 Node* NewNode = new Node;
		 NewNode->Data = NewData;
		 NewNode->PrevNode = NULL;
		 NewNode->NextNode = NULL;
		 return NewNode;
	}
	//노드 소멸
	void DestroyNode(Node* Node) {
		 delete Node;
	}
	//노드 추가
	void AppendNode(Node* NewNode) {
		//헤드 노드가 널이라면 새로 추가하는 노드가 헤드가 된다
		if (Head == NULL) {
			Head = NewNode;
			Head->NextNode = Head;
			Head->PrevNode = Head;
		}
		else {
			//테일과 헤드 사이에 NewNode 삽입
			Tail = Head->PrevNode;
			Tail->NextNode->PrevNode = NewNode;
			Tail->NextNode = NewNode;

			NewNode->NextNode = Head;
			NewNode->PrevNode = Tail; //새로운 테일의 PrevNode가 기존의 테일을 가리킴
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