#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	map<string,string> mp;
	map<string,int> chk;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		mp[x]=y;
		chk[x]=1;
	}
	while(q--)
	{
		int cnt=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=x.size();i++)
		{
			for(int j=0;j<x.size()-i+1;j++)
			{
				string str=x.substr(j,i);
				if(chk[str]==1)
				{
					string strl=x.substr(0,j);
					string strr=x.substr(j+i,n-j-i+1);
					string s=strl+mp[str]+strr;
					if(s==y) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
