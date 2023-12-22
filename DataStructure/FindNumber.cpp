#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, Num;
	cin >> N;
	vector<int> V(N);
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		V.push_back(temp);
	}

	sort(V.begin(), V.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Num;
		if (binary_search(V.begin(), V.end(), Num))
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}

	return 0;

}