#include<bits/stdc++.h>
using namespace std;
int l[100005],s[100005],r[10005],c[10005],b[10005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
				cin>>s[j];
		}
		for(int k=1;k<=q;k++)
			cin>>r[k]>>c[k];
		for(int i=1;i<=q;i++)
		{
			if(r[i]==c[i]) b[i]=1;
			else b[i]=0;
		}
	}
	for(int i=1;i<=q;i++)
		cout<<b[i];
	return 0;
}
