#include <iostream>

using namespace std;

void InsertionSort(int List[], int n)
{
	int i, j, Key;

	//�ε��� 0�� �̹� ���ĵ� ������ ����.
	for(i=1; i<n; i++)
	{
		Key = List[i]; //���� ���Ե� ������ i��° ������ Key ������ ����

		//���� ���ĵ� �迭�� i - 1�����̹Ƿ� i - 1��°���� �������� �����Ѵ�.
		// j ���� ������ �ƴϾ�� �ǰ�
		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�

		for(j=1-1; j>=0 && List[j]>Key; j--)
		{
			List[j + 1] = List[j]; //���ڵ��� ���������� �̵�
		}

		List[j + 1] = Key;
	}

}


int main(){

	int N, M;
	cin >> N;

	int* Arr = new int[N+1];

	for(int i=0; i<N; i++)
	{
		cin >> Arr[i];
	}

	cin >> M;
	Arr[N] = M;

	InsertionSort(Arr, N+1);

	for(int i=0; i<N+1; i++)
	{
		cout << Arr[i] << " ";
	}

	return 0;
}