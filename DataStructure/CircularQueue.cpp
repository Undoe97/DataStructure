#include<iostream>
using namespace std;

#define MAX_QUEUE_SIZE 20

int main() {

	class CircularQueue {
	private:
		int Data[MAX_QUEUE_SIZE]; // 요소의 배열
		int Front; //첫번째 요소 보다 한칸 앞의 위치
		int Rear; //마지막 요소 위치

	public:
		CircularQueue() {
			Front = Rear = 0;
		}
		~CircularQueue() {
		}
		void EnQueue(int Val) {
			if (isFull()) {//큐가 포화이면 오버플로우
				cout << "Queue Overflow!";
				exit(EXIT_FAILURE);
			}
			else {//아니면 Rear가 1증가하고 데이터 삽입
				Rear = (Rear + 1) % MAX_QUEUE_SIZE; //큐 사이즈만큼 나머지 연산
				Data[Rear] = Val;
			}
		}
		int DeQueue() {
			if (isEmpty()) {//큐가 비어있으면 언더플로우
				cout << "Queue Underflow!";
				exit(1);
			}
			else {//아니면 Front가 1증가하고 데이터 추출
				Front = (Front + 1) % MAX_QUEUE_SIZE;
				return Data[Front]; //프런트칸은 비어있기 때문
			}
		}
		int Peek() {
			if (isEmpty()) {
				cout << "Queue Underflow!";
				exit(1);
			}
			else {
				return Data[Front + 1]; //프런트칸은 비어있기때문
			}
		}
		bool isFull() {
			if (Front == (Rear+1) % MAX_QUEUE_SIZE) {
				return true;
			}
			else {
				return false;
			}
			//return (Front == (Rear+1) % MAX_QUEUE_SIZE;
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
		int Size() {
			return Rear - Front + 1;
		}
	};

	CircularQueue CQ;
	CQ.EnQueue(0);
	CQ.EnQueue(1);
	CQ.EnQueue(2);
	cout << CQ.DeQueue();
	cout << CQ.DeQueue();


	return 0;
}