#include<iostream>

using namespace std;

//버블 정렬은 정렬 범위를 하나씩 줄여나가며 정렬을 처리
//삽입 정렬은 정렬 범위를 하나씩 늘려나가며 정렬을 처리

void InsertionSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int Value = 0;

	for(i=1; i<Length; i++)
	{
		if(DataSet[i-1] <= DataSet[i]) //옆꺼와 다르면 넘어감
			continue;

		Value = DataSet[i];

		for(j=0; j<i; j++)
		{
			if(DataSet[j] > Value)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = Value;
				break;
			}
		}
	}

}

int main()
{
	int DataSet[] = { 6, 4, 2, 3 ,1 ,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	InsertionSort(DataSet, Length);

	for(i=0; i<Length; i++)
	{
		cout << DataSet[i];
	}

	cout << "\n";

	return 0;
}