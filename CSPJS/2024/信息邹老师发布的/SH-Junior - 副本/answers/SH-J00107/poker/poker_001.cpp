#include <bits/stdc++.h>
using namespace std;
map<string, bool> used;
char color[5] = {' ', 'D', 'C', 'H', 'S'};
char cnt[14] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int ans;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		used[s] = true;
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 13; j++)
		{
			string a = "";
			a += color[i];
			string b = "";
			b += cnt[j];
			string s = a + b;
			if(used[s] == true)
			{
				ans++;
			}
		}
	}
	printf("%d", 52 - ans);
	return 0;
}
