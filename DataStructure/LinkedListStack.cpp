#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListStack; //private 값에 접근가능
	private:
		int Data;
		Node* Link;
	public:
		Node(int _NewData) {
			Data = _NewData; //뉴데이터를 입력받아서 노드클래스의 멤버변수를 변경
			Link = NULL; //포인터는 항상 NULL로 초기화
		}
	};

	class LinkedListStack {
	private:
		Node* Top;

	public:
		LinkedListStack() { //생성자
			Top = NULL;
		}
		~LinkedListStack() { //소멸자
			//while (!IsEmpty()) 
				//delete Pop(); //Pop()함수가 반환한 값을 전부 삭제
		}
		bool IsEmpty() {
			return (Top == NULL);
		}
		//연결리스트스택에 isFull은 없음
		void Push(int NewData) {
			Node* NewNode = new Node(NewData); //새로운 노드 생성
			if (IsEmpty()) {
				Top = NewNode;; //스택이 비어있다면 바로 탑에 연결;
			}
			else {
				NewNode->Link = Top; // (1)추가될 노드의 Link가 Top이 가르키고 있는 노드를 가르키게 함
				Top = NewNode;// (2)헤드 포인터 Top이 새로 추가될 노드를 가르키게 함
			}
		}
		int Peek() {
			if (IsEmpty()) {
				return NULL;
			}
			else {
				return Top->Data;
			}
		}
		int Pop() {
			if (IsEmpty()) {
				return NULL;
			}
			else {
				Node* TempNode = Top; // (1)임시노드가 탑을 가르킴
				Top = TempNode->Link;// (2)탑이 임시노드의 다음노드를 가르킴 
				return TempNode->Data;// (3)임시노드를 반환
			}
		}
		int PrintSize() {
			int Size = 0;
			if (IsEmpty()) {
				return Size;
			}
			else {
				Node* TempNode = Top;
				while (!TempNode == NULL) {
					TempNode = TempNode->Link;
					Size++;
				}
				return Size;
			}
		}
		
	};
	LinkedListStack LLS;
	LLS.Push(0);
	LLS.Push(1);
	LLS.Push(2);
	LLS.Push(3);
	cout << LLS.Pop() << endl;
	cout << LLS.Pop() << endl;
	cout << LLS.Pop() << endl;
	cout << LLS.Pop() << endl;
	
	return 0;
}