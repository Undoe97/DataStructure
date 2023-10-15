#include <iostream>
using namespace std; 

class ArrayStack {

private:
	int Capacity;
	int Top; //스택의 맨 꼭대기 비어있으면 -1
	int* Arr; //동적 할당할 배열
public:
	ArrayStack(int _Size) {
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
		cout << "추가할 값 : " << Value << endl;
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
		cout << "삭제할 값 : " << Peek() << endl;
		
		return Arr[Top--]; // 
	}
	
	int GetSize() { //현재 스택 크기를 반환
		return Top + 1;
	}
	
	void PrintStack() {
		cout << "ArrayStack : [ ";
		for (int i = 0; i < GetSize(); i++) {
			if (i == 0) {
				cout << Arr[i];
			}
			else {
				cout << ", " << Arr[i];
			}
		}
		cout << " ]" << endl;
	}
};

int main() {
	ArrayStack St(5);

	St.Push(0);
	St.Push(1);
	St.Push(2);
	St.Push(3);
	St.PrintStack();
	St.Pop();
	St.Push(4);
	St.Pop();
	St.Pop();
	St.PrintStack();
	return 0;
}