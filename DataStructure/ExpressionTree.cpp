#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
typedef int ElementType;

typedef struct tagETNode
{
	struct tagETNode* Left;
	struct tagETNode* Right;
	ElementType Data;
}ETNode;

ETNode* CreateNode(ElementType NewData)
{
	ETNode* NewNode = new ETNode;
	NewNode->Data = NewData;
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;

	return NewNode;
}

void DestroyNode(ETNode* Node)
{
	delete Node;
}

void DestroyTree(ETNode* Root)
{
	if (Root == nullptr)
		return;

	DestroyTree(Root->Left);
	DestroyTree(Root->Right);
	DestroyNode(Root);
}

void PreorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;

	cout << Node->Data;
	PreorderPrintTree(Node->Left);
	PreorderPrintTree(Node->Right);
}

void InorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;
	InorderPrintTree(Node->Left);
	cout << Node->Data;
	InorderPrintTree(Node->Right);
}

void PostorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;
	PostorderPrintTree(Node->Left);
	PostorderPrintTree(Node->Right);
	cout << Node->Data;
}

void BuildExpressionTree(char* PostfixExpression, ETNode** Node)
{
	int Len = strlen(PostfixExpression); //���ڿ� ���� �Լ�
	char Token = PostfixExpression[Len - 1];
	PostfixExpression[Len - 1] = '\0';

	switch(Token)
	{
		//�������� ���
	case '+': case '-': case '*': case '/':
		(*Node) = CreateNode(Token);
		BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;

		//�ǿ������� ���
		default:
			(*Node) = CreateNode(Token);
			break;
	}

}

double Evaluate(ETNode* Tree) //���ϴ�
{
	char Temp[2];
	double Left = 0;
	double Right = 0;
	double Result = 0;

	if (Tree == nullptr)
		return 0;

	switch(Tree->Data)
	{
		//�������� ���
		case '+': case '-': case '*': case '/':
			Left  = Evaluate(Tree->Left);
			Right = Evaluate(Tree->Right);
	
			if (Tree->Data == '+') Result = Left + Right;
			else if (Tree->Data == '-') Result = Left - Right;
			else if (Tree->Data == '*') Result = Left * Right;
			else if (Tree->Data == '/') Result = Left / Right;
	
			break;
	
		//�ǿ������� ���
		default:
			memset(Temp, 0, sizeof(Temp)); //�Լ� �޸� �ʱ�ȭ
			Temp[0] = Tree->Data;
			Result = atof(Temp);
			break;
	
	}
	return Result;
}


int main()
{
	ETNode* Root = nullptr;

	char PostfixExperssion[20] = "71*52-/";
	BuildExpressionTree(PostfixExperssion, &Root);
	//Ʈ�� ���
	cout << "Preorder ...";
	PreorderPrintTree(Root);
	cout << "\n\n";
	cout << "Inorder ...";
	InorderPrintTree(Root);
	cout << "\n\n";
	cout << "Postorder ...";
	PostorderPrintTree(Root);
	cout << "\n\n";

	cout << "Evaulation Result : " << Evaluate(Root) << "\n";

	DestroyTree(Root);
	return 0;
}