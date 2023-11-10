#include<iostream>

using namespace std;

class BTNode
{
	friend class BinaryTree;
private:
	char Data;
	BTNode* Left;
	BTNode* Right;

public:
	BTNode(char _Data)
	{
		Data = _Data;
		Left = nullptr;
		Right = nullptr;
	}
	bool IsLeaf()
	{
		return (Left == nullptr && Right == nullptr);
	}
	char GetData()
	{
		return Data;
	}
	void SetData(int Val)
	{
		Data = Val;
	}
	void SetLeft(BTNode* Node)
	{
		Left = Node;
	}
	BTNode* GetLeft()
	{
		return Left;
	}
	void SetRight(BTNode* Node)
	{
		Right = Node;
	}
	BTNode* GetRight()
	{
		return Right;
	}
	
};

class BinaryTree
{
	BTNode* Root; //루트노드를 선언
public:
	BinaryTree() //생성자에서 루트를 널포인터로 초기화
	{
		Root = nullptr;
	}
	~BinaryTree()
	{

	}
	void SetRoot(BTNode* Node)
	{
		Root = Node;
	}
	BTNode* GetRoot()
	{
		return Root;
	}
	bool IsEmpty()
	{
		return (Root == nullptr);
	}

	BTNode* CreateNode(char Data)
	{
		BTNode* NewNode = new BTNode(Data);
		return NewNode;
	}

	void DestroyNode(BTNode* Node)
	{
		delete Node;
	}

	void DestroyTree(BTNode* Node) //트리를 부술때는 후위순회로
	{
		if (Node == nullptr)
			return;

		DestroyTree(Node->Left);
		DestroyTree(Node->Right);
		DestroyNode(Node);
	}
	void PreOrder(BTNode* Node) //전위순회
	{
		if (Node == nullptr)
			return;

		cout << Node->Data; //뿌리 노드 출력
		PreOrder(Node->Left); //왼쪽 하위 트리 출력
		PreOrder(Node->Right); //오른쪽 하위 트리 출력
	}

	void InOrder(BTNode* Node) //중위순회
	{
		if (Node == nullptr)
			return;

		InOrder(Node->Left); //왼쪽 하위 트리 출력
		cout << Node->Data; //뿌리 노드 출력
		InOrder(Node->Right); //오른쪽 하위 트리 출력
	}

	void PostOrder(BTNode* Node) //후위순회
	{
		if (Node == nullptr)
			return;

		PostOrder(Node->Left); //왼쪽 하위 트리 출력
		PostOrder(Node->Right); //오른쪽 하위 트리 출력
		cout << Node->Data; //뿌리 노드 출력
	}
};

int main()
{

	//각 노드와 왼쪽 자식 노드, 오른쪽 자식 노드 순서로 주어짐.
	BinaryTree BT;
	int N;
	char P, L, R;
	cin >> N;
	//for(int i =0; i<N ; i++)
	//{
	//	cin >> P >> L >> R;
	//}
	BTNode* A = BT.CreateNode('A');
	BTNode* B = BT.CreateNode('B');
	BTNode* C = BT.CreateNode('C');
	BTNode* D = BT.CreateNode('D');
	BTNode* E = BT.CreateNode('E');
	BTNode* F = BT.CreateNode('F');
	BTNode* G = BT.CreateNode('G');

	A->SetLeft(B);
	A->SetRight(C);

	B->SetLeft(D);
	C->SetLeft(E);
	C->SetRight(F);

	F->SetRight(G);

	cout << "Preorder..." << "\n";
	BT.PreOrder(A);
	cout << "\n\n";

	cout << "Inorder..." << "\n";
	BT.InOrder(A);
	cout << "\n\n";

	cout << "Postorder..." << "\n";
	BT.PostOrder(A);
	cout << "\n\n";

	return 0;
}