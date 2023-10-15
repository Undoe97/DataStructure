#include <iostream>
using namespace std;

class ArrayStack {

private:
	int Sum;
	int Capacity;
	int Top; //������ �� ����� ��������� -1
	int* Arr; //���� �Ҵ��� �迭
public:
	ArrayStack(int _Size) {
		Sum = 0;
		Top = -1;
		Capacity = _Size;
		Arr = new int[Capacity];
	}
	~ArrayStack() {
		delete[] Arr; // �迭�� �����Ҵ� �߱� ������ delete[]
	}
	int IsEmpty() { // ������ ����ֳ� Ȯ��
		return (Top == -1);
	}
	int IsFull() { // ������ �� ���ֳ� Ȯ��
		return (Top + 1 == Capacity);
	}
	void Push(int Value) {//���ÿ� �� �߰�
		if (IsFull()) {
			cout << "Stack Overflow!";
			exit(EXIT_FAILURE); //����
		}
		Arr[++Top] = Value;
	}
	int Peek() {//������ ������ ���� ��ȯ
		if (IsEmpty()) {
			exit(EXIT_FAILURE);
		}
		else {
			return Arr[Top];
		}
	}
	int Pop() {//������ ������ ���� ��ȯ(���� ��ȯ�ϱ� ������ int������ ����)�ϰ� ����
		if (IsEmpty()) {
			cout << "Stack Underflow!";
			exit(EXIT_FAILURE); //����
		}
		//cout << Peek() << endl;

		return Arr[Top--]; // 
	}

	int GetSize() { //���� ���� ũ�⸦ ��ȯ
		return Top + 1;
	}

	int Solution() {
		for (int i = 0; i < GetSize(); i++)
			Sum += Arr[i];
		return Sum;
	}
	
};

int main() {
	
	int K, Input;
	cin >> K;
	ArrayStack St(K);
	for (int i = 0; i < K; i++) {
		cin >> Input;
		if (Input == 0) {
			St.Pop();
		}
		else {
			St.Push(Input);
		}
	}
	cout << St.Solution();
	return 0;
}