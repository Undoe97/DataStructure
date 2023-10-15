#include <iostream>
using namespace std;

class Node {
    friend class CirCularDoublyLinkedList; //private 값에 접근가능
private:
    int Data; //값
    Node* NextNode; //다음 노드
    Node* PrevNode; //이전 노드

public:
    Node(int NewData) {
        Data = NewData;
        NextNode = NULL;
        PrevNode = NULL;
    }
};

class CirCularDoublyLinkedList { //리스트 생성 클래스
private:
    Node* Head;
public:
    CirCularDoublyLinkedList() {
        Head = nullptr;
    }

    void PushBack(int NewData) { //꼬리노드쪽부터 값을 넣어주는 함수
        Node* NewNode = new Node(NewData);
        if (Head == nullptr) { //헤드의 주소값이 nullptr이면 새 노드는 머리노드이자 꼬리노드
            Head = NewNode;
            NewNode->NextNode = Head; //머리
            NewNode->PrevNode = Head; //꼬리
        }
        else { //헤드의 주소값이 널이 아니라면 꼬리쪽에 노드가 추가
            NewNode->NextNode = Head; //새 노드의 다음노드 = 머리노드
            NewNode->PrevNode = Head->PrevNode; //새 노드의 이전노드 = 변경전 꼬리노드(=머리노드의 이전노드)
            Head->PrevNode->NextNode = NewNode; //꼬리노드의 다음노드(=머리노드의 이전노드의 다음노드) = 새 노드
            Head->PrevNode = NewNode; //꼬리노드(=머리노드의 이전노드) = 새노드
        }

    }

    /*
    void Append(int K, int NewData) { //k번째에 노드 추가, k번째 노드부터 꼬리노드까지 한칸씩 밀림
        Node* NewNode = new Node(NewData); //노드 생성
        if (K == 0) //헤드노드에 넣는 거라면
        {
            NewNode->NextNode = Head; //새 노드의 다음노드 = 변경전 머리노드
            NewNode->PrevNode = Head->PrevNode; //새노드의 이전노드 = 꼬리노드(변경전 머리노드의 이전노드)
            Head->PrevNode = NewNode; //꼬리노드 = 새 노드
            Head = NewNode; //머리노드 = 새 노드
        }
        else {
            Node* DestNode = Head; //k번째 노드까지 순차적으로 탐색
            for (int i = 0; i < K; i++) {
                DestNode = DestNode->NextNode;
            }
            NewNode->PrevNode = DestNode->PrevNode; //새 노드의 이전 노드 = K번째 노드의 이전노드
            NewNode->NextNode = DestNode; //새 노드의 다음 노드 = K번째 노드
            DestNode->PrevNode->NextNode = NewNode; //(K번째 노드의 이전노드)의 다음노드 = 새 노드
            DestNode->PrevNode = NewNode; // K번째 노드의 이전노드 = 새 노드
        }

    }

    void Remove(int K) { //K번째 노드를 삭제
        if (K == 0) { //만약 헤드노드를 삭제하면
            Node* TempNode = Head->NextNode; //일시노드 = 헤드의 다음 노드로 설정
            Head->PrevNode->NextNode = Head->NextNode; //꼬리노드의 다음노드 = 헤드의 다음노드(템프노드)
            Head->NextNode->PrevNode = Head->PrevNode; //템프노드의 이전노드 = 꼬리노드
            delete Head;
            Head = TempNode; //헤드의 빈자리를 변경
        }
        else {
            Node* DestNode = Head;
            for (int i = 0; i < K; i++) //k번째 노드까치 순차적으로 탐색
                DestNode = DestNode->NextNode;
            DestNode->PrevNode->NextNode = DestNode->NextNode; //k번째 노드의 이전노드(k-1)의 다음노드 = k번째 노드의 다음노드(k+1)
            DestNode->NextNode->PrevNode = DestNode->PrevNode; //k번째 노드의 다음노드(k+1)의 이전노드 = k번째 노드의 이전노드(k-1);
            delete DestNode; //k번째 노드의 주소값을 모두 삭제하였으니 k번째 노드 삭제
        }
    }
    */

    void Eliminate(int K, int J) { //K번째 사람 제거 & 출력 함수, J명까지
        Node* Current = Head;
        for (int i = 0; i < K-1; i++) {// 헤드에서 출발하기 때문에 K-1번째 사람까지
            Current = Current->NextNode;
        }
        if (J == 0) { // 처음 사람일때
            cout << Current->Data;
        }
        else {
            cout << ", " << Current->Data; //뒷 사람
        }
        Head = Current->NextNode;
        Current->PrevNode->NextNode = Current->NextNode; //k번째 노드의 이전노드(k-1)의 다음노드 = k번째 노드의 다음노드(k+1)
        Current->NextNode->PrevNode = Current->PrevNode; //k번째 노드의 다음노드(k+1)의 이전노드 = k번째 노드의 이전노드(k-1);
        delete Current; //k번째 노드의 주소값을 모두 삭제하였으니 k번째 노드 삭제
    }
};

int main() {
    CirCularDoublyLinkedList CDLL;
    int N, K; //N명의 사람이 앉아있고 K번째 사람 제거
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        CDLL.PushBack(i + 1);
    }
    cout << "<";
    for (int j = 0; j < N; j++)
        CDLL.Eliminate(K, j);
    cout << ">";

}