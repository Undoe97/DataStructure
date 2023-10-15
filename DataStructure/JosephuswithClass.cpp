#include <iostream>
using namespace std;

class Node {
    friend class CirCularDoublyLinkedList; //private ���� ���ٰ���
private:
    int Data; //��
    Node* NextNode; //���� ���
    Node* PrevNode; //���� ���

public:
    Node(int NewData) {
        Data = NewData;
        NextNode = NULL;
        PrevNode = NULL;
    }
};

class CirCularDoublyLinkedList { //����Ʈ ���� Ŭ����
private:
    Node* Head;
public:
    CirCularDoublyLinkedList() {
        Head = nullptr;
    }

    void PushBack(int NewData) { //��������ʺ��� ���� �־��ִ� �Լ�
        Node* NewNode = new Node(NewData);
        if (Head == nullptr) { //����� �ּҰ��� nullptr�̸� �� ���� �Ӹ�������� �������
            Head = NewNode;
            NewNode->NextNode = Head; //�Ӹ�
            NewNode->PrevNode = Head; //����
        }
        else { //����� �ּҰ��� ���� �ƴ϶�� �����ʿ� ��尡 �߰�
            NewNode->NextNode = Head; //�� ����� ������� = �Ӹ����
            NewNode->PrevNode = Head->PrevNode; //�� ����� ������� = ������ �������(=�Ӹ������ �������)
            Head->PrevNode->NextNode = NewNode; //��������� �������(=�Ӹ������ ��������� �������) = �� ���
            Head->PrevNode = NewNode; //�������(=�Ӹ������ �������) = �����
        }

    }

    /*
    void Append(int K, int NewData) { //k��°�� ��� �߰�, k��° ������ ���������� ��ĭ�� �и�
        Node* NewNode = new Node(NewData); //��� ����
        if (K == 0) //����忡 �ִ� �Ŷ��
        {
            NewNode->NextNode = Head; //�� ����� ������� = ������ �Ӹ����
            NewNode->PrevNode = Head->PrevNode; //������� ������� = �������(������ �Ӹ������ �������)
            Head->PrevNode = NewNode; //������� = �� ���
            Head = NewNode; //�Ӹ���� = �� ���
        }
        else {
            Node* DestNode = Head; //k��° ������ ���������� Ž��
            for (int i = 0; i < K; i++) {
                DestNode = DestNode->NextNode;
            }
            NewNode->PrevNode = DestNode->PrevNode; //�� ����� ���� ��� = K��° ����� �������
            NewNode->NextNode = DestNode; //�� ����� ���� ��� = K��° ���
            DestNode->PrevNode->NextNode = NewNode; //(K��° ����� �������)�� ������� = �� ���
            DestNode->PrevNode = NewNode; // K��° ����� ������� = �� ���
        }

    }

    void Remove(int K) { //K��° ��带 ����
        if (K == 0) { //���� ����带 �����ϸ�
            Node* TempNode = Head->NextNode; //�Ͻó�� = ����� ���� ���� ����
            Head->PrevNode->NextNode = Head->NextNode; //��������� ������� = ����� �������(�������)
            Head->NextNode->PrevNode = Head->PrevNode; //��������� ������� = �������
            delete Head;
            Head = TempNode; //����� ���ڸ��� ����
        }
        else {
            Node* DestNode = Head;
            for (int i = 0; i < K; i++) //k��° ����ġ ���������� Ž��
                DestNode = DestNode->NextNode;
            DestNode->PrevNode->NextNode = DestNode->NextNode; //k��° ����� �������(k-1)�� ������� = k��° ����� �������(k+1)
            DestNode->NextNode->PrevNode = DestNode->PrevNode; //k��° ����� �������(k+1)�� ������� = k��° ����� �������(k-1);
            delete DestNode; //k��° ����� �ּҰ��� ��� �����Ͽ����� k��° ��� ����
        }
    }
    */

    void Eliminate(int K, int J) { //K��° ��� ���� & ��� �Լ�, J�����
        Node* Current = Head;
        for (int i = 0; i < K-1; i++) {// ��忡�� ����ϱ� ������ K-1��° �������
            Current = Current->NextNode;
        }
        if (J == 0) { // ó�� ����϶�
            cout << Current->Data;
        }
        else {
            cout << ", " << Current->Data; //�� ���
        }
        Head = Current->NextNode;
        Current->PrevNode->NextNode = Current->NextNode; //k��° ����� �������(k-1)�� ������� = k��° ����� �������(k+1)
        Current->NextNode->PrevNode = Current->PrevNode; //k��° ����� �������(k+1)�� ������� = k��° ����� �������(k-1);
        delete Current; //k��° ����� �ּҰ��� ��� �����Ͽ����� k��° ��� ����
    }
};

int main() {
    CirCularDoublyLinkedList CDLL;
    int N, K; //N���� ����� �ɾ��ְ� K��° ��� ����
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        CDLL.PushBack(i + 1);
    }
    cout << "<";
    for (int j = 0; j < N; j++)
        CDLL.Eliminate(K, j);
    cout << ">";

}