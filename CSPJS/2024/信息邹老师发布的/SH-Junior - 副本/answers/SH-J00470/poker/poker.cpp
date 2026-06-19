#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	map<string,bool> mp;
	map<string,bool>::iterator it;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		mp[s]=true;
	}
	for(it=mp.begin();it!=mp.end();it++)
	    ans-=(*it).second;
	cout<<ans<<endl;
	return 0;
}
