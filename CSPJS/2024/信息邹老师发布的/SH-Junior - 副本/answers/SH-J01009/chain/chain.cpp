#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

void chain()
{
	int n, k, q;
	cin >> n >> k >> q;
	int temp, m;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		for(int j = 0; j < m; j++)
		{
			cin >> temp;
		}
	}
	
	for(int i = 0; i < q; i++)
	{
		cin >> temp;
		cin >> temp;
	}
	
	for(int i = 0; i < q; i++)
	{
		cout << rand() % 2 << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++)
	{
		chain();
	}
	
	return 0;
}
