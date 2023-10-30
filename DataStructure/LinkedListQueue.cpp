#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListQueue; //private ���� ���� ����
	private:
		int Data;
		Node* Link;
	public:
		Node(int _NewData) {
			Data = _NewData; //�������͸� �Է¹޾Ƽ� ���Ŭ������ ��������� ����
			Link = nullptr; //�����ʹ� �׻� NULL�� �ʱ�ȭ
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
				Front = Rear = NewNode; //ť�� ����ִٸ� ����Ʈ ��� ����带 �߰�
			}
			else {
				Rear->Link = NewNode; //����带 ��� ����Ű�� ���� ����
				Rear = NewNode; //����尡 ��� �ǰ�
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
			Node* TempNode = Front; //(1) ����Ʈ ������ ���� ������忡 ����
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
				return Value; //(3) �ӽó�尪 ��ȯ
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