#include<bits/stdc++.h>
using namespace std;

int n,q;
const int N=2e5+10;
string S1[N],S2[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string k1,k2;
		cin>>k1;
		cin>>k2;
		S1[i]=k1;
		S2[i]=k2;
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=0;i<a.size();i++)
		{
			string x,y,z;
			x=a.substr(0,i);
			for(int j=1;j<=n;j++)
			{
				if(i+S1[j].size()>a.size()) continue;
				string h=a.substr(i,S1[j].size());
				if(h==S1[j])
				{
					y=S2[j];
					z=a.substr(i+S1[j].size());
					if((x+y+z)==b) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
