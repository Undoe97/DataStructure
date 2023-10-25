#include<iostream>
#include<string>
using namespace std;

int main() {

	class CircularQueue {
	private:
		int* Arr;// �����Ҵ��� �迭
		int Capacity;
		int Front; //ù��° ��� ���� ��ĭ ���� ��ġ
		int Rear; //������ ��� ��ġ

	public:
		CircularQueue(int _Capacity) {
			Capacity = _Capacity + 1;
			Arr = new int[Capacity]; //Front�� ��ĭ
			Front = Rear = 0;
		}
		~CircularQueue() {
			delete[] Arr; //�迭�� �����Ҵ� �߱� ������ delete[]
		}
		void Enqueue(int Val) {
			if (isFull()) {//ť�� ��ȭ�̸� �����÷ο�
				cout << "Queue Overflow!";
				exit(EXIT_FAILURE);
			}
			else {//�ƴϸ� Rear�� 1�����ϰ� ������ ����
				Rear = (Rear + 1) % Capacity; //ť �����ŭ ������ ����
				Arr[Rear] = Val;
			}
		}
		int Dequeue() {
			if (isEmpty()) {//ť�� ��������� ����÷ο�
				cout << "Queue Underflow!";
				exit(1);
			}
			else {//�ƴϸ� Front�� 1�����ϰ� ������ ����
				Front = (Front + 1) % Capacity;
				return Arr[Front]; //����Ʈĭ�� ����ֱ� ����
			}
		}
		int Peek() {
			if (isEmpty()) {
				cout << "Queue Underflow!";
				exit(1);
			}
			else {
				return Arr[(Front + 1) % Capacity]; //����Ʈĭ�� ����ֱ⶧��
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
		int Size() { //���� ť�� ����� ���ϴ� �Լ�
			return (Rear - Front + Capacity) % Capacity;
		}
		void PrintQueue() {
			for (int i = 0; i < Capacity; i++) {
				cout << Arr[i] << "\n";
			}
		}
	};
	//���� ������ ���� �ݺ� == while(
	//1. N���� ī�尡 �ִ� = Eequeue() N��
	//2. ���� ���� �ִ� ī�带 ������ == Dequeue()
	//3. ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��. == Dequeue(), Enqueue();
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