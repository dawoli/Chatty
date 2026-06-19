#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.length();
	for(int t = 0;t < n;t++)
	{
		if(s[t] >= '0' && s[t] <= '9')
		{
			cnt[s[t] - '0']++;
		}
	}
	bool flag = 0;
	for(int t = 9;t >= 1;t--)
	{
		while(cnt[t]--)
		{
			flag = 1;
			cout << t;
		}
	}
	if(!flag)
	{
		cout << 0;
	}
	else
	{
		while(cnt[0]--)
		{
			cout << 0;
		}
	}
	return 0;
 } 
