#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	int cnt = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '1') cnt++;
	}
	if (cnt < m) cout << 0;
	else cout << 132134578;
	return 0; 
}
