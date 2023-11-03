#include<iostream>

using namespace std;

class BinaryNode
	{
	friend class BinaryTree;
private:
	int Data;
	BinaryNode* Left; //���� ���
	BinaryNode* Right; //������ ���

public:
	BinaryNode(int Val) //�����ڷ� ����� ������� �ʱ�ȭ
	{
		Data = Val;
		Left = nullptr;
		Right = nullptr;
	}
	~BinaryNode()
	{
		
	}
	bool IsLeaf() //�ܸ� ��� �ΰ�?
	{
		return (Left == nullptr && Right == nullptr);
	}
	int GetData()
	{
		return Data;
	}
	void SetData(int Val)
	{
		Data = Val;
	}
	BinaryNode* GetLeft()
	{
		return Left;
	}
	BinaryNode* GetRight()
	{
		return Right;
	}
	void SetLeft(BinaryNode* L)
	{
		Left = L;
	}
	void SetRight(BinaryNode* R)
	{
		Right = R;
	}
};

class BinaryTree
{
	BinaryNode* Root; //��Ʈ��带 ����
public:
	BinaryTree() //�����ڿ��� ��Ʈ�� �������ͷ� �ʱ�ȭ
	{
		Root = nullptr;
	}
	~BinaryTree()
	{
		
	}
	void SetRoot(BinaryNode* Node)
	{
		Root = Node;
	}
	BinaryNode* GetRoot()
	{
		return Root;
	}
	bool IsEmpty()
	{
		return (Root == nullptr);
	}
	void PreOrder(BinaryNode* Node) //������ȸ
	{
		if (Node != nullptr)
		{
			cout << " [" << (char)Node->GetData() << "] "; //�Ѹ� ��� ���

			if (Node->GetLeft() != nullptr)
				PreOrder(Node->GetLeft()); //���� ���� Ʈ�� ���

			if (Node->GetRight() != nullptr)
				PreOrder(Node->GetRight()); //������ ���� Ʈ�� ���
		}
	}

	void InOrder(BinaryNode* Node) //������ȸ
	{
		if(Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft()); //���� ���� Ʈ�� ���

			cout << " [" << (char)Node->GetData() << "] ";  //�Ѹ� ��� ���

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); //������ ���� Ʈ�� ���
		}
		
	}

	void PostOrder(BinaryNode* Node) //������ȸ
	{
		if (Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft()); //���� ���� Ʈ�� ���

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); //������ ���� Ʈ�� ���

			cout << " [" << (char)Node->GetData() << "] ";  //�Ѹ� ��� ���
		}
	}
};


int main()
{
	
	

}