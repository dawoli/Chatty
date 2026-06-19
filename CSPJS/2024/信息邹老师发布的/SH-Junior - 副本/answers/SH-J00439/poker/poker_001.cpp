#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		mp[s]=1;
	}
	int cnt=52;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		cnt--;
	}
	cout<<cnt;
	return 0;
}
