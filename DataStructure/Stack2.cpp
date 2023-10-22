#include<iostream>

using namespace std;

int main() {

	class Node {
		friend class LinkedListStack; //private ���� ���ٰ���
	private:
		int Data;
		Node* Link;
	public:
		Node(int _NewData) {
			Data = _NewData; //�������͸� �Է¹޾Ƽ� ���Ŭ������ ��������� ����
			Link = NULL; //�����ʹ� �׻� NULL�� �ʱ�ȭ
		}
	};

	class LinkedListStack {
	private:
		Node* Top;

	public:
		LinkedListStack() { //������
			Top = NULL;
		}
		~LinkedListStack() { //�Ҹ���
			//while (!IsEmpty()) 
				//delete Pop(); //Pop()�Լ��� ��ȯ�� ���� ���� ����
		}
		bool IsEmpty() {
			return (Top == NULL);
		}
		//���Ḯ��Ʈ���ÿ� isFull�� ����
		void Push(int NewData) {
			Node* NewNode = new Node(NewData); //���ο� ��� ����
			if (IsEmpty()) {
				Top = NewNode;; //������ ����ִٸ� �ٷ� ž�� ����;
			}
			else {
				NewNode->Link = Top; // (1)�߰��� ����� Link�� Top�� ����Ű�� �ִ� ��带 ����Ű�� ��
				Top = NewNode;// (2)��� ������ Top�� ���� �߰��� ��带 ����Ű�� ��
			}
		}
		int Peek() {
			if (IsEmpty()) {
				return -1; //���ٸ� -1�� ��ȯ
			}
			else {
				return Top->Data;
			}
		}
		int Pop() {
			if (IsEmpty()) {
				return -1; //���ٸ� -1�� ��ȯ
			}
			else {
				Node* TempNode = Top; // (1)�ӽó�尡 ž�� ����Ŵ
				Top = TempNode->Link;// (2)ž�� �ӽó���� ������带 ����Ŵ 
				return TempNode->Data;// (3)�ӽó�带 ��ȯ
			}
		}
		int PrintSize() {
			int Size = 0;
			if (IsEmpty()) { 
				return Size;
			}
			else {
				Node* TempNode = Top; // (1)�ӽó�尡 ž�� ����Ŵ
				while (!TempNode == NULL) { // (2)�ӽó�尡 NULL�� �ƴϸ�~
					TempNode = TempNode->Link; // (3)�ӽó�忡 �ӽó���� ������� ����(����)
					Size++; 
				}
				return Size;
			}
		}

	};
		//1 X: ���� X�� ���ÿ� �ִ´�. (1 �� X �� 100,000) == Push(X);
		//2 : ���ÿ� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�. == Pop();
		//3 : ���ÿ� ����ִ� ������ ������ ����Ѵ�. == PrintSize();
		//4 : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�. == IsEmpty();
		//5 : ���ÿ� ������ �ִٸ� �� ���� ������ ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�. == Peek();

	LinkedListStack LLS;

	int N, Input; //����� ��
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