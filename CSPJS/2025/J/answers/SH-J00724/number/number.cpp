#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol a[15];


int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string s;
	cin>>s;
	
	for(int i = 0;i < s.size();i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[s[i] - '0'] ++;
		}
	}
	
	for(int i = 9;i >= 0;i --)
	{
		for(int j = 1;j <= a[i];j ++)
		{
			cout<<i;
		}
	}
	
	return 0;
}
