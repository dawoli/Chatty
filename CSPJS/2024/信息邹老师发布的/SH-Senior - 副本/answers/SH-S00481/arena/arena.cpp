#include<bits/stdc++.h>
#define Hatsune return
#define Miku 0
using namespace std;

typedef long long ll;
const ll N=1e5+10,M=1e5+10,KK=20;

ll n,m,XX[4],aa[N],a[N],c[M],K,d[KK][N],ans[M],win[M];
string s;
ll nowwin[KK],nowK;

ll batle(ll R,ll val,ll A,ll B)
{
	if(val)
	{
		if(a[B]>=R) return B;
		return A;
	}
	if(a[A]>=R) return A;
	return B;
}

void Solve()
{
	for(ll i=1;i<=n;i++) win[i]=nowwin[i]=0;
	//jisuan xunliansai saiguo
	ll now=1;nowK=0;
	for(ll i=1,b,id;i<=n;i++)
	{
		if(i==1)
		{
			win[1]=1;
			continue;
		}
		
		if(now<i)
		{
			now*=2;
			nowK++;
			nowwin[nowK]=win[i-1];
			//if(nowK==3) cout<<nowwin[nowK]<<"\n";
		}
		
		b=(i+1)>>1,id=i;
		nowwin[0]=i;bool flag=1;int qwqwin;
		for(ll j=1;j<=nowK;j++)
		{
			if((!flag))
			{
				flag=0;
				if(id&1)
				{
					qwqwin=batle(j,d[j][b],qwqwin,0);
					flag=0;
				}
				else
				{
					qwqwin=batle(j,d[j][b],nowwin[j],qwqwin);
				}
				b++,id++,b>>=1,id>>=1;
				win[i]=qwqwin;
				continue;
			}
			if(id&1)
			{
				nowwin[j]=batle(j,d[j][b],nowwin[j-1],0);
				flag=0;qwqwin=nowwin[j];
			}
			else
			{
				nowwin[j]=batle(j,d[j][b],nowwin[j],nowwin[j-1]);
			}
			b++,id++,b>>=1,id>>=1;
		}
		if(flag) win[i]=nowwin[nowK];
		else win[i]=qwqwin;
	}	
	
}

ll tmp[N];

void solve()
{
	/*
	for(ll i=1;i<=n;i++) tmp[i]=a[i];
	ll tmpn=n,now=1;
	for(ll i=1;i<=n;i++)
	{
		if(now<i) now*=2;
		n=now;
		for(ll j=i+1;j<=n;j++) a[j]=0;
		for(ll j=1;j<=i;j++)
		{
			solve();
		}
		n=tepn;
		for(ll i=1;i<=n;i++) a[i]=tmp[i];
	}*/
	Solve();
	ll res=0;
	for(ll i=1;i<=m;i++)
	{
		res^=(win[c[i]]*i);
	}
	cout<<res<<"\n";
	
}

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>aa[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	ll now=1;
	while(now<n) now*=2,K++;
	for(ll i=1;i<=K;i++)
	{
		cin>>s;
		for(ll j=1;j<=(1<<(K-i));j++) d[i][j]=s[j-1]-'0';
	}
	ll T;cin>>T;
	while(T--)
	{
		cin>>XX[0]>>XX[1]>>XX[2]>>XX[3];
		for(ll i=1;i<=n;i++) a[i]=aa[i]^XX[i%4];
		solve();
	}
	Hatsune Miku;
}
