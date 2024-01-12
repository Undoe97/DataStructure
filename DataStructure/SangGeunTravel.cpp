#include <iostream>

using namespace std;

int main()
{
	//MST의 원칙 : 간선의 개수 = (정점의 개수)-1
	int T;
	cin >> T;

	//N은 정점(노드) M은 간선(에지)
	for(int i=0; i<T; i++)
	{
		int N, M, a, b;
		cin >> N >> M;
		for(int j=0; j<M; j++)
		{
			cin >> a >> b;
		}
		cout << N-1 << '\n'; 
	}
	return 0;
}