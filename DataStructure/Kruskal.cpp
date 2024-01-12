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

	//오름차순 정렬 기준
	bool operator<(Edge &edge)
	{
		return this->distance < edge.distance;
	}
};

//부모 탐색
int findParent(int node)
{
	if (parent[node] == node) return node;
	return findParent(parent[node]);
}

//두 노드를 작은값을 기준으로 연결
void unionParent(int node1, int node2)
{
	node1 = findParent(node1);
	node2 = findParent(node2);
	if (node1 < node2) 
		parent[node2] = node1;
	else 
		parent[node1] = node2;

}

//싸이클이 존재하면 true, 아니면 false를 반환
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

	//간선 가중치 기준 오름차순 정렬
	sort(v.begin(), v.end());

	//부모노드 초기화
	for(int i=1; i<=5; i++)
	{
		parent[i] = i;
	}

	int sum = 0; //간선의 가중치 합

	for(int i=0; i<v.size(); i++)
	{
		//싸이클 여부 확인
		if(!isCycle(v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}

	//최소 신장 트리 가중치 합 출력
	printf("%d\n", sum);

	return 0;

}