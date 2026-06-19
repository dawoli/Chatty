#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,a[10005][20005],l[100005],qq[100005][3],b[200005]={0};
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int k=1;k<=l[i];k++)
			{
				cin>>a[i][k];
				b[a[i][k]]=1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>qq[i][1]>>qq[i][2];
			if(b[qq[i][2]]==0||b[1]==0||n==1)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<1<<endl;
				continue;
			}
		}
	}
	return 0;
}
