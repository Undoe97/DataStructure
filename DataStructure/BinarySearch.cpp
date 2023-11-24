#include<iostream>

using namespace std;

int BinarySearch(int Arr[], int Low, int High, int Key)
{
	while(Low <= High) // ���� ����1 �˻� ����
	{
		int Mid = Low + (High - Low) / 2;
		if (Arr[Mid] == Key) //�ѹ��� �˻� ����
			return Mid;
		else if (Arr[Mid] > Key) //�߰����� �˻������� ũ��
			High = Mid - 1;
		else //�߰����� �˻������� ������
			Low = Mid + 1;
	}
	return -1; //���� ����2 (Low > High) �˻� ����
}

int main()
{
	int Arr[10] = { 5, 10, 14, 25, 27, 32, 39, 45, 52, 60 };
	cout << BinarySearch(Arr, 0, 9, 27) << "��°�� �ֽ��ϴ�.";

	return 0;
}