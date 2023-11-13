#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//ù° �ٿ��� �ǿ������� ����(1�̻� 26����)
	//��° �ٿ��� ���� ǥ���
	//��° �ٺ��� N+2��° �ٱ��� �� �ǿ����ڿ� �����ϴ� ���� �־���
	//3��° �ٿ��� A�� �ش��ϴ� ��, 4��° �ٿ��� B, 5��° �ٿ��� C

	//�ΰ��� ����ǥ���, ��ǻ�ʹ� ����ǥ����� ����
	//�ǿ����ڴ� ���ÿ� �ְ�,
	//�����ڸ� ������ �� ���� ������ ������ �ϰ�
	//�������� �ƴ϶�� �ٽ� ���ÿ� �ִ´�.
	//�Ҽ��� ��°�ڸ����� ����ϱ� ���� cout ��ü�� fixed�� pricision�� ���

int main()
{
	//C�� C++�� ǥ�� stream�� ����ȭ�� ���� ����
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //�Է¹��� �ǿ�����(operand) ����
	string Postfix; //�Է¹��� ���� ǥ���

	vector<int> Operand(26); //�Է��� �ǿ�����
	stack<double> ST;

	cin >> N;
	cin >> Postfix;

	for(int i=0; i<N; i++)
	{
		cin >> Operand[i];
	}
	//����ǥ����� ���� ��ŭ �ݺ�
	for(int i=0; i< Postfix.length(); i++)
	{
		//�ǿ������� ���
		if(Postfix[i] >= 'A' && Postfix[i] <= 'Z')
		{
			ST.push(Operand[Postfix[i] - 'A']);
		}
		else //�������� ���
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
				ST.push(Temp); //����� Ǫ��
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ST.top() << '\n';

	return 0;
}