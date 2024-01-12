#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int parent[5];

class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	//�������� ���� ����
	bool operator<(Edge &edge)
	{
		return this->distance < edge.distance;
	}
};

//�θ� Ž��
int findParent(int node)
{
	if (parent[node] == node) return node;
	return findParent(parent[node]);
}

//�� ��带 �������� �������� ����
void unionParent(int node1, int node2)
{
	node1 = findParent(node1);
	node2 = findParent(node2);
	if (node1 < node2) 
		parent[node2] = node1;
	else 
		parent[node1] = node2;

}

//����Ŭ�� �����ϸ� true, �ƴϸ� false�� ��ȯ
bool isCycle(int node1, int node2)
{
	node1 = findParent(node1);
	node2 = findParent(node2);
	if (node1 == node2) return true;
	else return false;
}

int main()
{
	vector<Edge> v;
	v.push_back(Edge(0, 1, 10));
	v.push_back(Edge(0, 2, 5));
	v.push_back(Edge(1, 2, 7));
	v.push_back(Edge(1, 3, 4));
	v.push_back(Edge(2, 3, 3));
	v.push_back(Edge(2, 4, 2));
	v.push_back(Edge(3, 4, 1));

	//���� ����ġ ���� �������� ����
	sort(v.begin(), v.end());

	//�θ��� �ʱ�ȭ
	for(int i=1; i<=5; i++)
	{
		parent[i] = i;
	}

	int sum = 0; //������ ����ġ ��

	for(int i=0; i<v.size(); i++)
	{
		//����Ŭ ���� Ȯ��
		if(!isCycle(v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}

	//�ּ� ���� Ʈ�� ����ġ �� ���
	printf("%d\n", sum);

	return 0;

}