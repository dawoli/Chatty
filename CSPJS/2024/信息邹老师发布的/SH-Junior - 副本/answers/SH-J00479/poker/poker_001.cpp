#include <bits/stdc++.h>
using namespace std;
string str[80];
bool f[300][300];
int n, p;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> str[i], f[str[i][0]][str[i][1]] = true;
	for(int i = 1; i <= 280; i++)
		for(int j = 1; j <= 280; j++)
			if(f[i][j])
				p++;
	cout << 52 - p;
	return 0;
}

