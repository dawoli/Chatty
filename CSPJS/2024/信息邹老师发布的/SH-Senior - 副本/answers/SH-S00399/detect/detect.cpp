#include<bits/stdc++.h>
using namespace std;
int T, n, m, l, vl, ans, maxx, t;
int d[100005], v[100005], a[100005], p[100005], r[1000006];
void work()
{
	ans=0;
	cin>>n>>m>>l>>vl;
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&d[i],&v[i],&a[i]);
	maxx=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d ",&t);
		maxx=max(maxx,t);
	}
	for(int i=1;i<=n;i++)
		if(d[i]<=maxx && sqrt(double(v[i])*double(v[i])*1.0+2.0*double(a[i])*double(maxx-d[i]))>vl)
			ans++;
	cout<<ans<<" "<<m-1*int(bool(ans))<<"\n";
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
		work();
	return 0;
}
