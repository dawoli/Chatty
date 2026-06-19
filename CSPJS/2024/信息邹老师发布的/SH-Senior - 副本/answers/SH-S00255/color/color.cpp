#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define V 1000010
int a[N],box[V],dp[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,d=0,maxn=0;
		cin>>n;
		for(int i=1;i<=1000000;i++) box[i]=-1e12;
		for(int i=1;i<=n;i++) cin>>a[i];
		dp[1]=0;
		box[0]=0;
		for(int i=2;i<=n;i++)
		{
			int nd=(a[i]==a[i-1])*a[i];
			dp[i]=max(maxn,box[a[i]]+a[i])-nd;
			maxn=max(maxn,dp[i]);
			box[a[i-1]]=max(box[a[i-1]],dp[i]);
			d+=nd;
		}
		cout<<maxn+d<<endl;
	}
	return 0;
}

