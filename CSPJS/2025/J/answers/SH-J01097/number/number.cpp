#include<bits/stdc++.h>
using namespace std;
#define int long long

int num[1000010];
bool cmp(int a, int b)
{
	return a > b;
}
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) if(s[i] >= '0' && s[i] <= '9') num[++cnt] = s[i] - '0';
	sort(num + 1, num + cnt + 1, cmp);
	if(num[1] == 0) 
	{
		cout << 0 << endl;
		return 0;
	}
	else
	{
		for(int i = 1; i <= cnt; i++) cout << num[i];
		cout << endl;
	}	
	return 0;
}
