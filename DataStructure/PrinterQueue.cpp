#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListQueue; //private ���� ���� ����
	private:
		int Data;
		int Sequence;
		Node* Link;
	public:
		Node(int _NewData, int _Sequence) {
			Data = _NewData;//�������͸� �Է¹޾Ƽ� ���Ŭ������ ��������� ����
			Sequence = _Sequence;
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
		~LinkedListQueue()
		{
			while (!IsEmpty())
				delete DeQueue();
		}

		bool IsEmpty() const
		{
			if (Front == Rear) {
				return true;
			}
			else {
				return false;
			}
		}

		void EnQueue(int NewData, int Sequence) {
			Node* NewNode = new Node(NewData, Sequence);
			if (IsEmpty()) {
				Front = Rear = NewNode; //ť�� ����ִٸ� ����Ʈ ��� ����带 �߰�
			}
			else {
				Rear->Link = NewNode; //����带 ��� ����Ű�� ���� ����
				Rear = NewNode; //����尡 ��� �ǰ�
			}
			++Count;
		}

		Node* DeQueue() {
			Node* TempNode = Front; //(1) ����Ʈ ������ ���� ������忡 ����
			if (IsEmpty())
			{
				return NULL;
			}
			else
			{
				TempNode = Front;
				
				Front = TempNode->Link;
				if (Front == nullptr)
					Rear = nullptr;
				--Count;
				return TempNode; //(3) �ӽó�尪 ��ȯ
			}

		}

		Node* Peek() {
			if (IsEmpty())
			{
				return nullptr;
			}
			else
			{
				return Front;
			}
		}

		void PrintSize() {
			cout << Count;
		}

		void Compare(int N, int M)
		{
			int PrintCount = 0;
			for (int i = 0; i < N; i++)
			{
				if (Peek()->Data < Front->Link->Data)
				{
					int Temp = Peek()->Sequence;
					EnQueue(DeQueue()->Data, Temp);
				}
				
			}
			cout << PrintCount;
		}
	};

	//1.���� ť�� ���� �տ� �ִ� ������ �߿䵵�� Ȯ��
	//2.������ ������ �� ���� �������� �߿䵵�� ���� ������ �ִٸ�, ť�� �ڿ� ���ġ or �μ�
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		LinkedListQueue LLQ;
		for(int i=0; i<N; i++)
		{
			int Pri;
			cin >> Pri;
			LLQ.EnQueue(Pri, i);
		}
		//Front ������ Priority ���� �ٸ� ����� ���ؼ� ���� ū �߿䵵�� Front�� ����
		LLQ.Compare(N, M);
		
	}

	

	

	return 0;
}