#include<bits/stdc++.h>
using namespace std;
int l = 1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k[100005];
	for(int i = 0;i < s.length();i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			k[l] = s[i] - 48;
			l += 1;
		}
	}
	l -= 1;
	sort(k + 1,k + l + 1);
	for(int i = l;i >= 1;i --)
	{
		cout<<k[i]<<"";
	}
	return 0;
} 
