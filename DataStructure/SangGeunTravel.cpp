#include <iostream>

using namespace std;

int main()
{
	//MST�� ��Ģ : ������ ���� = (������ ����)-1
	int T;
	cin >> T;

	//N�� ����(���) M�� ����(����)
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