/*

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
const ll M=18;
ll T,n,m,K,tot,k,a[N],aa[N],c[N],p2[M],X[5],res1[M][N];
bool d[18][N],flag[N],flag2[N][M],flag3,flag4;
char gc()
{
	char ch=getchar();
	while (ch!='0'&&ch!='1') ch=getchar();
	return ch;
}
void dfs(ll R,ll G,ll l,ll r)
{
	if (R==0) return;
	ll mid=(l+r) >> 1;
	dfs(R-1,G*2-1,l,mid);
	dfs(R-1,G*2,mid+1,r);
	if (flag3)
	{
		for (int i=l;i<=mid;i++)
			if (flag[i])
			{
				res1[R-1][G*2-1]=i;
				break;
			}
		for (int i=mid+1;i<=r;i++)
			if (flag[i])
			{
				res1[R-1][G*2]=i;
				break;
			}
	}
	//cout << endl << R-1 << ' ' << l << ' ' << r << endl;
	//for (int i=l;i<=r;i++) cout << flag[i] << ' ';
	//cout << endl;
	if (d[R][G]==0)
	{
		bool flag1=false; // random 
		for (int i=l;i<=mid;i++)
			if (flag[i]&&i>tot)
			{
				flag1=true;
				break;
			}
		if (flag1)
		{
			for (int i=l;i<=mid;i++)
				if (flag[i]&&i<=tot&&a[i]<R)
					flag[i]=false;
			return;
		}
		bool flagw=false,flagl=false;
		for (int i=l;i<=mid;i++)
		{
			if (!flag[i]) continue;
			if (a[i]>=R) flagw=true;
			else flagl=true;
		}
		if (!flagw) // lose
		{
			for (int i=l;i<=mid;i++) flag[i]=false;
			return;
		}
		else if (!flagl) // win
		{
			for (int i=mid+1;i<=r;i++) flag[i]=false;
			return;
		}
		for (int i=l;i<=mid;i++)
			if (flag[i]&&a[i]<R)
				flag[i]=false;
	}
	else
	{
		bool flag1=false; // random 
		for (int i=mid+1;i<=r;i++)
			if (flag[i]&&i>tot)
			{
				flag1=true;
				break;
			}
		if (flag1)
		{
			for (int i=mid+1;i<=r;i++)
				if (flag[i]&&i<=tot&&a[i]<R)
					flag[i]=false;
			return;
		}
		bool flagw=false,flagl=false;
		for (int i=mid+1;i<=r;i++)
		{
			if (!flag[i]) continue;
			if (a[i]>=R) flagw=true;
			else flagl=true;
		}
		if (!flagw) // lose
		{
			for (int i=mid+1;i<=r;i++) flag[i]=false;
			return;
		}
		else if (!flagl) // win
		{
			for (int i=l;i<=mid;i++) flag[i]=false;
			return;
		}
		for (int i=mid+1;i<=r;i++)
			if (flag[i]&&a[i]<R)
				flag[i]=false;
	}
}
ll solve()
{
	ll k=lower_bound(p2,p2+K+1,tot)-p2;
	for (int i=1;i<=p2[k];i++) flag[i]=true;
	dfs(k,1,1,p2[k]);
	if (flag3)
	{
		for (int i=1;i<=p2[k];i++)
			if (flag[i])
			{
				res1[k][1]=i;
				break;
			}
	}
	ll res=0;
	for (int i=1;i<=p2[k];i++) res+=(flag[i]*i);
	//cout << endl << tot << endl;
	//for (int i=1;i<=p2[k];i++) cout << flag[i] << ' ';
	//cout << endl;
	return res;
}
ll dfs2(ll R,ll G,ll l,ll r)
{
	if (R==0) return l;
	if (l>tot) return l;
	if (r<=tot) return res1[R][G];
	ll mid=(l+r) >> 1;
	ll x=dfs2(R-1,G*2-1,l,mid),y=dfs2(R-1,G*2,mid+1,r);
	if (x>tot) return x;
	if (a[x]>=R) return x;
	return y;
}
ll solve2()
{
	ll k=lower_bound(p2,p2+K+1,tot)-p2;
	ll res=dfs2(k,1,1,p2[k]);
	if (res>tot) return (p2[k]-res+1)*(p2[k]+res)/2;
	return res;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> aa[i];
	for (int i=1;i<=m;i++) cin >> c[i];
	p2[K=0]=1;
	while (p2[K]<n) p2[K+1]=p2[K]*2,K++;
	flag4=false;
	for (int i=1;i<=K;i++)
		for (int j=1;j<=p2[K-i];j++)
			d[i][j]=gc()=='1',flag4|=d[i][j];
	cin >> T;
	while (T--)
	{
		for (int i=0;i<4;i++) cin >> X[i];
		for (int i=1;i<=n;i++) a[i]=(aa[i]^X[i%4]);
		ll Ans=0;
		if (n<=5e3)
		{
			flag3=false;
			for (int i=1;i<=m;i++) tot=c[i],Ans^=solve()*i;
		}
		else if (!flag4)
		{
			flag3=true;
			tot=n;
			solve();
			for (int i=1;i<=m;i++) tot=c[i],Ans^=i*solve2();
		}
		else
		{
			flag3=true;
			tot=n;
			solve();
			for (int i=1;i<=m;i++)
			{
				ll k=lower_bound(p2,p2+K+1,c[i])-p2;
				Ans^=i*res1[k][1];
			}
		}
		cout << Ans << endl;
	}
	return 0;
}
