#include <iostream>
using namespace std;

class ArrayStack {

private:
	int Sum;
	int Capacity;
	int Top; //스택의 맨 꼭대기 비어있으면 -1
	int* Arr; //동적 할당할 배열
public:
	ArrayStack(int _Size) {
		Sum = 0;
		Top = -1;
		Capacity = _Size;
		Arr = new int[Capacity];
	}
	~ArrayStack() {
		delete[] Arr; // 배열로 동적할당 했기 때문에 delete[]
	}
	int IsEmpty() { // 스택이 비어있나 확인
		return (Top == -1);
	}
	int IsFull() { // 스택이 꽉 차있나 확인
		return (Top + 1 == Capacity);
	}
	void Push(int Value) {//스택에 값 추가
		if (IsFull()) {
			cout << "Stack Overflow!";
			exit(EXIT_FAILURE); //종료
		}
		Arr[++Top] = Value;
	}
	int Peek() {//스택의 마지막 값을 반환
		if (IsEmpty()) {
			exit(EXIT_FAILURE);
		}
		else {
			return Arr[Top];
		}
	}
	int Pop() {//스택의 마지막 값을 반환(값을 반환하기 때문에 int형으로 선언)하고 삭제
		if (IsEmpty()) {
			cout << "Stack Underflow!";
			exit(EXIT_FAILURE); //종료
		}
		//cout << Peek() << endl;

		return Arr[Top--]; // 
	}

	int GetSize() { //현재 스택 크기를 반환
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