#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int Arr[1001] = {0, };
	int Time, Temp = 0;
	for(int i=0; i<N; i++)
	{
		cin >> Time;
		Arr[i] = Time;
	}

	//cout << "정렬 전 : " << "\n";
	//for(int i=0; i<N; i++)
	//{
	//	cout << Arr[i];
    //}
	
	//cout << "\n";

	for(int i=0; i<N-1; i++)
	{
		for(int j=0; j<N-i-1; j++)
		{
			if(Arr[j] > Arr[j+1])
			{
				Temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = Temp;
			}
		}
	}

	//cout << "정렬 결과 : " << "\n";
	//for(int i=0; i<N; i++)
	//{
	//	cout << Arr[i];
	//}

	//cout << "\n";

	int Sum = 0;
	
	for(int i=0; i<N; i++)
	{
		Sum = Sum + Arr[i] * (N-i);
	}
	//Arr[0]은 5번 더해지고, Arr[1]은 4번 더해지고, Arr[2]은 3번 더해지고, Arr[3]은 2번 더해지고, Arr[4]은 1번 더해진다.
	cout << Sum;

}