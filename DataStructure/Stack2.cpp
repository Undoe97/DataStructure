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
				return -1; //없다면 -1을 반환
			}
			else {
				return Top->Data;
			}
		}
		int Pop() {
			if (IsEmpty()) {
				return -1; //없다면 -1을 반환
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
				Node* TempNode = Top; // (1)임시노드가 탑을 가르킴
				while (!TempNode == NULL) { // (2)임시노드가 NULL이 아니면~
					TempNode = TempNode->Link; // (3)임시노드에 임시노드의 다음노드 대입(루프)
					Size++; 
				}
				return Size;
			}
		}

	};
		//1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000) == Push(X);
		//2 : 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다. == Pop();
		//3 : 스택에 들어있는 정수의 개수를 출력한다. == PrintSize();
		//4 : 스택이 비어있으면 1, 아니면 0을 출력한다. == IsEmpty();
		//5 : 스택에 정수가 있다면 맨 위의 정수를 출력한다.없다면 - 1을 대신 출력한다. == Peek();

	LinkedListStack LLS;

	int N, Input; //명령의 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Input;
		switch (Input) {
			case 1:
				int X;
				cin >> X;
				LLS.Push(X);
				break;
			case 2:
				cout << LLS.Pop() << "\n";
				break;
			case 3:
				cout << LLS.PrintSize() << "\n";
				break;
			case 4:
				cout << LLS.IsEmpty() << "\n";
				break;
			case 5:
				cout << LLS.Peek() << "\n";
				break;
		}
	}

	return 0;
}