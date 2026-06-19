#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,ans;
map<string,string> m;
map<int,int> v;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		m[a]=b;
		v[a.size()]=1;
	}
	while(q--)
	{
		ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<(int)a.size();i++)
		{
			if(a[i]!=b[i])
			{
				l=i;
				break;
			}
		}
		for(int i=(int)a.size()-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				r=i;
				break;
			}
		}
		for(int i=0;i<=l;i++)
		{
			for(int j=r-l+1;j<=(int)a.size()-i;j++)
			{
				if(!v[j]) continue;
				if(m[a.substr(i,j)]==b.substr(i,j)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
