#include <bits/stdc++.h>
using namespace std;
int cnt[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int ans = s[i]-'0';
			cnt[ans]++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		while(cnt[i]>0)
		{
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}
