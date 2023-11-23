#include <iostream>

using namespace std;

int Flag = 0;

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

bool IsArraySame(int Arr1[], int Arr2[])
{

	for(int i=0; i<sizeof(Arr1); i++)
	{
		if(Arr1[i] != Arr2[i])
		{
			Flag = 0;
			return false;
		}
	}
	Flag = 1;
	return true;
}

int Partition(int DataSet[], int CompArr[], int Left, int Right) //분할하는 함수
{
	if (IsArraySame(DataSet, CompArr))
	{
		Flag = 1;
		return -1;
	}
	//Pivot == 기준
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;

		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);
	IsArraySame(DataSet, CompArr);

	return Right;
}

void QuickSort(int DataSet[], int CompArr[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, CompArr, Left, Right);

		QuickSort(DataSet, CompArr, Left, Index - 1); //재귀호출
		QuickSort(DataSet, CompArr, Index + 1, Right); //재귀호출

		IsArraySame(DataSet, CompArr);
	}
}

int main()
{
	int i;
	int N;
	cin >> N;

	int* A = new int[N];
	int* B = new int[N];

	for(int j=0; j<N; j++)
	{
		cin >> A[j];
	}

	for (int k=0; k<N; k++)
	{
		cin >> B[k];
	}

	QuickSort(A, B, 0, N - 1);
	cout << Flag;

	cout << "\n";


	for (i = 0; i < N; i++)
	{
		cout << A[i];
	}
	cout << "\n";

	return 0;
}