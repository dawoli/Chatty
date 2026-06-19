#include<bits/stdc++.h>
using namespace std;
int s[1009], x, n, m;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		cin >> s[i];
	}
	x = s[0];
	for (int i = 0; i < n * m; i++)
	{
		if (s[i] < s[i + 1])
		{
			int g = s[i];
			s[i] = s[i + 1];
			s[i + 1] = g;
		}
	} 
	int i = 1, j = 1, y = 0;
	while (s[y] != x)
	{
		if (i == m && j == n)
		{
			break;
		}
		if (i % 2 == 1 && j < n)
		{
			j++;
		}
		else if (i % 2 == 0 && j > 1)
		{
			j--;
		}
		else if (j == n || j == 1)  i++;
		y++;
	}
	cout << i << " " << j << endl;
	return 0;
}
