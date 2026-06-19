#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int number[10000001];
string input;

int judge_number(char x)
{
	if(x == '1')
		return 1;
	if(x == '2')
		return 2;
	if(x == '3')
		return 3;
	if(x == '4')
		return 4;
	if(x == '5')
		return 5;
	if(x == '6')
		return 6;
	if(x == '7')
		return 7;
	if(x == '8')
		return 8;
	if(x == '9')
		return 9;
	if(x == '0')
		return 0;
	return 10;
}

char num[1000001];

bool cmp(char a, char b)
{
	//cout<<a<<" "<<b<<endl;
	//cout<<(judge_number(a) > judge_number(b))<<" "<<judge_number(a)<<" "<<judge_number(b)<<endl;
	cout<<(a>b)<<endl;
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out ", "w", stdout);
	
	cin>>input;
	//cout<<input<<endl;
	int temp = 0;
	for(int i=0; i<input.length(); i++)
	{
		int tmp = judge_number(input[i]);
		if(tmp != 10){
			//number[temp] = tmp;
			num[temp] = input[i];
			//cout<<num[temp]<<endl;
			temp++;
		}
		
	}
	//sort(number, number+temp, cmp);
	
	/*
	int ans = 0;
	for(int i=0; i<temp; i++)
	{
		ans = ans * 10;
		ans = ans + number[i];
	}
	cout<<ans<<endl;
	*/
	
	string ans = "";
	char i = '9';
	while(i >= '0')
	{
		for(int j = 0; j < temp; j++)
		{
			if(num[j] == i){
				ans += num[j];
				num[j] = 'N';
			}
		}
		i = i - 1;
	}
	cout<<ans<<endl;
	
	/*
	for(int i=0; i<temp; i++)
	{
		cout<<number[temp];
	}
	cout<<endl;
	*/

	return 0;
 } 
