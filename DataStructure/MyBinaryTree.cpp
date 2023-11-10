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
	BTNode* Root; //��Ʈ��带 ����
public:
	BinaryTree() //�����ڿ��� ��Ʈ�� �������ͷ� �ʱ�ȭ
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

	void DestroyTree(BTNode* Node) //Ʈ���� �μ����� ������ȸ��
	{
		if (Node == nullptr)
			return;

		DestroyTree(Node->Left);
		DestroyTree(Node->Right);
		DestroyNode(Node);
	}
	void PreOrder(BTNode* Node) //������ȸ
	{
		if (Node == nullptr)
			return;

		cout << Node->Data; //�Ѹ� ��� ���
		PreOrder(Node->Left); //���� ���� Ʈ�� ���
		PreOrder(Node->Right); //������ ���� Ʈ�� ���
	}

	void InOrder(BTNode* Node) //������ȸ
	{
		if (Node == nullptr)
			return;

		InOrder(Node->Left); //���� ���� Ʈ�� ���
		cout << Node->Data; //�Ѹ� ��� ���
		InOrder(Node->Right); //������ ���� Ʈ�� ���
	}

	void PostOrder(BTNode* Node) //������ȸ
	{
		if (Node == nullptr)
			return;

		PostOrder(Node->Left); //���� ���� Ʈ�� ���
		PostOrder(Node->Right); //������ ���� Ʈ�� ���
		cout << Node->Data; //�Ѹ� ��� ���
	}
};

int main()
{

	//�� ���� ���� �ڽ� ���, ������ �ڽ� ��� ������ �־���.
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