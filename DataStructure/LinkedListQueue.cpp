#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListQueue; //private 값에 접근 가능
	private:
		int Data;
		Node* Link;
	public:
		Node(int _NewData) {
			Data = _NewData; //뉴데이터를 입력받아서 노드클래스의 멤버변수를 변경
			Link = nullptr; //포인터는 항상 NULL로 초기화
		}
	};

	class LinkedListQueue {
	private:
		Node* Front;
		Node* Rear;
		int Count;

	public:
		LinkedListQueue() {
			Front = Rear = nullptr;
			Count = 0;
		}
		~LinkedListQueue() = default;

		bool IsEmpty() const
		{
			if (Front == Rear) {
				return true;
			}
			else {
				return false;
			}
		}

		void EnQueue(int NewData) {
			Node* NewNode = new Node(NewData);
			if (IsEmpty()) {
				Front = Rear = NewNode; //큐가 비어있다면 프론트 리어에 뉴노드를 추가
			}
			else {
				Rear->Link = NewNode; //뉴노드를 리어가 가르키는 곳에 연결
				Rear = NewNode; //뉴노드가 리어가 되게
			}
			++Count;
		}
		int MyDeQueue()
		{
			int Value;
			Node* TempNode = Front;
			if(Front == Rear && !IsEmpty())
			{
				Front = Rear = nullptr;
			}
			else if(Front != Rear)
			{
				Front = TempNode->Link;
			}
			Value = TempNode->Data;
			return Value;
		}
		int DeQueue() {
			int Value;
			Node* TempNode = Front; //(1) 프론트 포인터 값을 템프노드에 저장
			if(IsEmpty())
			{
				return NULL;
			}
			else
			{
				TempNode = Front;
				Value = TempNode->Data;
				Front = TempNode->Link;
				if (Front == nullptr)
					Rear = nullptr;
				--Count;
				delete TempNode;
				return Value; //(3) 임시노드값 반환
			}

		}

		int Peek() {
			if(IsEmpty())
			{
				return NULL;
			}
			else
			{
				return Front->Data;
			}
		}

		void PrintSize() {
			cout << Count;
		}
	};
	LinkedListQueue LLQ;
	LLQ.EnQueue(0);
	LLQ.EnQueue(1);
	LLQ.EnQueue(2);
	cout << LLQ.DeQueue();
	cout << LLQ.MyDeQueue();
	

	return 0;
}