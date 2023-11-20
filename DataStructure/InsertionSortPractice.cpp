#include <iostream>

using namespace std;

void InsertionSort(int List[], int n)
{
	int i, j, Key;

	//인덱스 0은 이미 정렬된 것으로 본다.
	for(i=1; i<n; i++)
	{
		Key = List[i]; //현재 삽입될 숫자인 i번째 정수를 Key 변수로 복사

		//현재 정렬된 배열은 i - 1까지이므로 i - 1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동

		for(j=1-1; j>=0 && List[j]>Key; j--)
		{
			List[j + 1] = List[j]; //레코드의 오른쪽으로 이동
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