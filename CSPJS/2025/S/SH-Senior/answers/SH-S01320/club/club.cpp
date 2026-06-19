#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][4],bel[N];
void solve()
{
	int n;cin>>n;
	int c[4]={0,0,0,0},ans=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[i][mx])mx=j;
		}
		ans+=a[i][mx];
		bel[i]=mx;
		c[bel[i]]++;
	}
	int mx=0;
	for(int i=1;i<=3;i++)
	{
		if(c[i]>c[mx])mx=i;
	}
	if(c[mx]<=n/2)
	{
		printf("%lld\n",ans);
		return;
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(bel[i]==mx)
		{
			int mx1=0;
			for(int j=1;j<=3;j++)if(j!=mx)
			{
				if(a[i][j]>a[i][mx1])mx1=j;
			}
			v.push_back(a[i][mx1]-a[i][mx]);
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<c[mx]-n/2;i++)ans+=v[i];
	printf("%lld\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--)solve();
}
