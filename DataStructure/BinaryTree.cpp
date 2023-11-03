#include<iostream>

using namespace std;

class BinaryNode
	{
	friend class BinaryTree;
private:
	int Data;
	BinaryNode* Left; //왼쪽 노드
	BinaryNode* Right; //오른쪽 노드

public:
	BinaryNode(int Val) //생성자로 노드의 멤버변수 초기화
	{
		Data = Val;
		Left = nullptr;
		Right = nullptr;
	}
	~BinaryNode()
	{
		
	}
	bool IsLeaf() //단말 노드 인가?
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
	BinaryNode* Root; //루트노드를 선언
public:
	BinaryTree() //생성자에서 루트를 널포인터로 초기화
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
	void PreOrder(BinaryNode* Node) //전위순회
	{
		if (Node != nullptr)
		{
			cout << " [" << (char)Node->GetData() << "] "; //뿌리 노드 출력

			if (Node->GetLeft() != nullptr)
				PreOrder(Node->GetLeft()); //왼쪽 하위 트리 출력

			if (Node->GetRight() != nullptr)
				PreOrder(Node->GetRight()); //오른쪽 하위 트리 출력
		}
	}

	void InOrder(BinaryNode* Node) //중위순회
	{
		if(Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft()); //왼쪽 하위 트리 출력

			cout << " [" << (char)Node->GetData() << "] ";  //뿌리 노드 출력

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); //오른쪽 하위 트리 출력
		}
		
	}

	void PostOrder(BinaryNode* Node) //후위순회
	{
		if (Node != nullptr)
		{
			if (Node->GetLeft() != nullptr)
				InOrder(Node->GetLeft()); //왼쪽 하위 트리 출력

			if (Node->GetRight() != nullptr)
				InOrder(Node->GetRight()); //오른쪽 하위 트리 출력

			cout << " [" << (char)Node->GetData() << "] ";  //뿌리 노드 출력
		}
	}
};


int main()
{
	
	

}