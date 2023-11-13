#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//첫째 줄에는 피연산자의 개수(1이상 26이하)
	//둘째 줄에는 후위 표기식
	//셋째 줄부터 N+2번째 줄까지 각 피연산자에 대응하는 값이 주어짐
	//3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B, 5번째 줄에는 C

	//인간은 중위표기식, 컴퓨터는 후위표기식이 편함
	//피연산자는 스택에 넣고,
	//연산자를 만나면 두 개를 꺼내어 연산을 하고
	//마지막이 아니라면 다시 스택에 넣는다.
	//소숫점 둘째자리까지 출력하기 위해 cout 객체의 fixed와 pricision을 사용

int main()
{
	//C와 C++의 표준 stream의 동기화를 끊는 역할
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //입력받을 피연산자(operand) 개수
	string Postfix; //입력받을 후위 표기식

	vector<int> Operand(26); //입력한 피연산자
	stack<double> ST;

	cin >> N;
	cin >> Postfix;

	for(int i=0; i<N; i++)
	{
		cin >> Operand[i];
	}
	//후위표기식의 길이 만큼 반복
	for(int i=0; i< Postfix.length(); i++)
	{
		//피연산자인 경우
		if(Postfix[i] >= 'A' && Postfix[i] <= 'Z')
		{
			ST.push(Operand[Postfix[i] - 'A']);
		}
		else //연산자인 경우
		{
			if(!ST.empty())
			{
				double Temp = ST.top();
				ST.pop();
				switch (Postfix[i])
				{
				case '+':
					Temp = ST.top() + Temp;
					break;
				case '-':
					Temp = ST.top() - Temp;
					break;
				case '*':
					Temp = ST.top() * Temp;
					break;
				case '/':
					Temp = ST.top() / Temp;
					break;
				}
				ST.pop();
				ST.push(Temp); //계산결과 푸쉬
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ST.top() << '\n';

	return 0;
}