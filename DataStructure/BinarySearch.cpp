#include<iostream>

using namespace std;

int BinarySearch(int Arr[], int Low, int High, int Key)
{
	while(Low <= High) // 종료 조건1 검색 성공
	{
		int Mid = Low + (High - Low) / 2;
		if (Arr[Mid] == Key) //한번에 검색 성공
			return Mid;
		else if (Arr[Mid] > Key) //중간값이 검색값보다 크면
			High = Mid - 1;
		else //중간값이 검색값보다 작으면
			Low = Mid + 1;
	}
	return -1; //종료 조건2 (Low > High) 검색 실패
}

int main()
{
	int Arr[10] = { 5, 10, 14, 25, 27, 32, 39, 45, 52, 60 };
	cout << BinarySearch(Arr, 0, 9, 27) << "번째에 있습니다.";

	return 0;
}