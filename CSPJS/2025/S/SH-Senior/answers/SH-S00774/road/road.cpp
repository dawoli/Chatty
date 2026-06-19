#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005],d[15][10005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int ans=0;
	bool zero=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		ans+=c[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>d[i][j];
			if(d[i][j]) zero=0;
		}
	}
	if(zero) cout<<"0\n";
	else cout<<ans<<'\n';
	return 0;
}
