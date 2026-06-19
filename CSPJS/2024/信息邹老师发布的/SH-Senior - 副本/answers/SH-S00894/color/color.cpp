/*

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const ll N=2e3+5;
const ll N2=2e5+5;
ll T,n,m,a[N2],b[N2],f[2][N][2]; // f[i][j][0/1]表示 a[i]颜色为 0/1 另一数为 j 滚动数组 
ll f2[N2][12][2];
ll cal(ll x,ll y){return x==y?b[x]:0;}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		m=unique(b+1,b+n+1)-(b+1);
		for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		//for (int i=1;i<=n;i++) cout << a[i] << ' ';
		//cout << endl;
		ll ans=0;
		if (n<=2e4)
		{
			for (int j=0;j<=m;j++)
				f[0][j][0]=f[0][j][1]=-INF;
			f[0][0][0]=f[0][0][1]=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<=m;j++) f[i&1][j][0]=f[i&1][j][1]=-INF;
				for (int j=0;j<=m;j++)
				{
					f[i&1][a[i-1]][0]=max(f[i&1][a[i-1]][0],f[!(i&1)][j][1]+cal(a[i],j));
					f[i&1][a[i-1]][1]=max(f[i&1][a[i-1]][1],f[!(i&1)][j][0]+cal(a[i],j));
					f[i&1][j][0]=max(f[i&1][j][0],f[!(i&1)][j][0]+cal(a[i],a[i-1]));
					f[i&1][j][1]=max(f[i&1][j][1],f[!(i&1)][j][1]+cal(a[i],a[i-1]));
				}
				//for (int j=1;j<=m;j++) cout << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << endl;
			}
			for (int i=1;i<=m;i++)
				for (int j=0;j<=1;j++)
					ans=max(ans,f[n&1][i][j]);
		}
		else
		{
			for (int i=0;i<=n;i++)
				for (int j=0;j<=m;j++)
					f2[i][j][0]=f2[i][j][1]=-INF;
			f2[0][0][0]=f2[0][0][1]=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<=m;j++)
				{
					f2[i][a[i-1]][0]=max(f2[i][a[i-1]][0],f2[i-1][j][1]+cal(a[i],j));
					f2[i][a[i-1]][1]=max(f2[i][a[i-1]][1],f2[i-1][j][0]+cal(a[i],j));
					f2[i][j][0]=max(f2[i][j][0],f2[i-1][j][0]+cal(a[i],a[i-1]));
					f2[i][j][1]=max(f2[i][j][1],f2[i-1][j][1]+cal(a[i],a[i-1]));
				}
				//for (int j=1;j<=m;j++) cout << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << endl;
			}
			for (int i=1;i<=m;i++)
				for (int j=0;j<=1;j++)
					ans=max(ans,f2[n][i][j]);
		}
		cout << ans << endl;
	}
	return 0;
}
