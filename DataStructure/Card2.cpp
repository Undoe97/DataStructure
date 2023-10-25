#include<iostream>
#include<string>
using namespace std;

int main() {

	class CircularQueue {
	private:
		int* Arr;// 동적할당할 배열
		int Capacity;
		int Front; //첫번째 요소 보다 한칸 앞의 위치
		int Rear; //마지막 요소 위치

	public:
		CircularQueue(int _Capacity) {
			Capacity = _Capacity + 1;
			Arr = new int[Capacity]; //Front는 빈칸
			Front = Rear = 0;
		}
		~CircularQueue() {
			delete[] Arr; //배열로 동적할당 했기 때문에 delete[]
		}
		void Enqueue(int Val) {
			if (isFull()) {//큐가 포화이면 오버플로우
				cout << "Queue Overflow!";
				exit(EXIT_FAILURE);
			}
			else {//아니면 Rear가 1증가하고 데이터 삽입
				Rear = (Rear + 1) % Capacity; //큐 사이즈만큼 나머지 연산
				Arr[Rear] = Val;
			}
		}
		int Dequeue() {
			if (isEmpty()) {//큐가 비어있으면 언더플로우
				cout << "Queue Underflow!";
				exit(1);
			}
			else {//아니면 Front가 1증가하고 데이터 추출
				Front = (Front + 1) % Capacity;
				return Arr[Front]; //프런트칸은 비어있기 때문
			}
		}
		int Peek() {
			if (isEmpty()) {
				cout << "Queue Underflow!";
				exit(1);
			}
			else {
				return Arr[(Front + 1) % Capacity]; //프런트칸은 비어있기때문
			}
		}
		bool isFull() {
			if (Front == (Rear + 1) % Capacity) {
				return true;
			}
			else {
				return false;
			}
			//return (Front == (Rear+1) % Capacity;
		}
		bool isEmpty() {
			if (Front == Rear) {
				return true;
			}
			else {
				return false;
			}
			//return (Front == Rear);
		}
		int Size() { //현재 큐의 사이즈를 구하는 함수
			return (Rear - Front + Capacity) % Capacity;
		}
		void PrintQueue() {
			for (int i = 0; i < Capacity; i++) {
				cout << Arr[i] << "\n";
			}
		}
	};
	//한장 남을때 까지 반복 == while(
	//1. N장의 카드가 있다 = Eequeue() N번
	//2. 제일 위의 있는 카드를 버린다 == Dequeue()
	//3. 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다. == Dequeue(), Enqueue();
	int N;
	cin >> N;
	CircularQueue CQ(N);
	
	for (int i = 1; i <= N; i++) {
		CQ.Enqueue(i);
	}
	//cout << "SIZE() : " << CQ.Size() << endl; 
	
	while (CQ.Size() != 1) {
		CQ.Dequeue();
		CQ.Enqueue(CQ.Dequeue());
	}
	cout << CQ.Peek();
	
	return 0;
}