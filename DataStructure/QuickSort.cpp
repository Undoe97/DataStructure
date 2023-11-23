#include <iostream>

using namespace std;

void Swap(int* A, int *B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(int DataSet[], int Left, int Right) //�����ϴ� �Լ�
{
	//Pivot == ����
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while(Left<=Right)
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

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if(Left<Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1); //���ȣ��
		QuickSort(DataSet, Index + 1, Right); //���ȣ��

	}
}

int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	QuickSort(DataSet, 0, Length - 1);

	for(i=0; i<Length; i++)
	{
		cout << DataSet[i];
	}
	cout << "\n";

	return 0;
}