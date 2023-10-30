#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListQueue; //private 값에 접근 가능
	private:
		int Data;
		int Sequence;
		Node* Link;
	public:
		Node(int _NewData, int _Sequence) {
			Data = _NewData;//뉴데이터를 입력받아서 노드클래스의 멤버변수를 변경
			Sequence = _Sequence;
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
				Front = Rear = NewNode; //큐가 비어있다면 프론트 리어에 뉴노드를 추가
			}
			else {
				Rear->Link = NewNode; //뉴노드를 리어가 가르키는 곳에 연결
				Rear = NewNode; //뉴노드가 리어가 되게
			}
			++Count;
		}

		Node* DeQueue() {
			Node* TempNode = Front; //(1) 프론트 포인터 값을 템프노드에 저장
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
				return TempNode; //(3) 임시노드값 반환
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

	//1.현재 큐의 가장 앞에 있는 문서의 중요도를 확인
	//2.나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 있다면, 큐의 뒤에 재배치 or 인쇄
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
		//Front 노드안의 Priority 값을 다른 노드들과 비교해서 제일 큰 중요도가 Front에 오게
		LLQ.Compare(N, M);
		
	}

	

	

	return 0;
}