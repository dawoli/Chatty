#include <iostream>
using namespace std;

int stick[5001];
bool used[5001];
int N = 0;
int size;

void dfs(int n, int num, int Max, int he)
{
	int temp = 0;
	if(n == 0)
	{	
		if(he > 2 * Max)
		{
			N++;
		}
		return;
	}
	
	for(int i = num; i <= size - n; i++)
	{
		if(used[i] == 0)
		{
			used[i] = 1;
			temp = Max;
			Max = max(Max, stick[i]);
			he += stick[i];
			
			dfs(n - 1, i, Max, he);
			
			he -= stick[i];
			Max = temp;
			used[i] = 0;
		}
	}
}

int main()
{	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> size;
	
	for(int i = 0; i < size; i++)
	{
		cin >> stick[i];
	}
	
	for(int i = 3; i <= size; i++)
	{
		dfs(i, 0, 0, 0);
	}
	
	cout << N % 998244353 << endl;
	return 0;
}
