#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	string ss = "";
	for (int i = 0;i < s.size();i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			ss += s[i];
		}
	}
	sort(ss.begin(),ss.end());
	for (int i = ss.size() - 1;i >= 0;i--)
	{
		cout << ss[i];
	}
	return 0;
 } 
