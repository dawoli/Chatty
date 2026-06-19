#include <bits/stdc++.h>
using namespace std;
const int N=200005;
string a[N],b[N];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s,t;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--)
	{
		int ans=0;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++)
			if(s.find(a[j])!=s.npos)
			{
				string tmp=s; 
				int pos=s.find(a[j]),l=a[j].size();
				for(int i=1;i<=l;i++)
					tmp[pos+i-1]=b[j][i-1];
				if(tmp==t)
					ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
