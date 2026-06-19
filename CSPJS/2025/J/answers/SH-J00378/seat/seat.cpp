#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, arr[105] {};
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> arr[i];
	}
	int scr = arr[1];
	for (int i = 1; i <= n * m; i++)
	{
		for (int j = i+1; j <= n * m; j++)
		{
			if (arr[i] < arr[j]) swap(arr[i], arr[j]);
		}
	}
	int pos = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if (arr[i] == scr) 
		{
			pos = i;	
			break;
		}	
	}
	int row = pos % n;
	int line = pos / n;
	if (row)
	{
		line++;
		if (line % 2 == 0) row = n - row + 1;
	}
	else
	{
		if (line % 2 == 0) row = 1;
		else row = n;
	}
	cout << line << ' ' << row;
	return 0;
}
