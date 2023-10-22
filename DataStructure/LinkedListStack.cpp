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