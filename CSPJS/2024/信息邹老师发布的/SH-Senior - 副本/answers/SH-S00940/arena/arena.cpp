#include<bits/stdc++.h>
#define INF 2e9
#define ll long long
using namespace std;
const ll N=1e5+5,M=20;
string str;
bool d[M][M];
ll n,m,K,T,a0[N],a[N],c[N],LOG2[N],X[5],Ans[N],ans,Win[N];
ll cal(ll x)
{
	if(x==(1<<LOG2[x])) return LOG2[x];
	return LOG2[x]+1;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m; LOG2[1]=0;
	for(ll i=2;i<=n;i++) LOG2[i]=LOG2[i>>1]+1;
	for(ll i=1;i<=n;i++) cin>>a0[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	K=cal(n);
	for(ll R=1;R<=K;R++)
	{
		cin>>str;
		for(ll G=1;G<=str.size();G++) d[R][G]=str[G-1]-'0';
	}
	cin>>T;
	while(T--)
	{
		cin>>X[0]>>X[1]>>X[2]>>X[3]; ans=0;
		for(ll i=1;i<=n;i++) a[i]=a0[i]^X[i%4];
		for(ll Q=1;Q<=m;Q++)
		{
			ll k=cal(c[Q]);
			if(c[Q]==(1<<k))
			{
				for(ll i=1;i<=(1<<k);i++) Win[i]=i;
				for(ll R=1;R<=k;R++)
					for(ll G=1;G<=(1<<(k-R));G++)
					{
						ll Pl_A=Win[2*G-1],Pl_B=Win[2*G],LZ;
						if(Pl_A>Pl_B)
						{
							if(d[R][G]) LZ=Pl_A;
							else LZ=Pl_B;
						}
						else
						{
							if(d[R][G]) LZ=Pl_B;
							else LZ=Pl_A;
						}
						if(a[LZ]>=R) Win[G]=LZ;
						else Win[G]=Win[2*G-1]+Win[2*G]-LZ;
					}
				Ans[Q]=Win[1];
			}
			else Ans[Q]=0;
//			cout<<Ans[Q]<<' ';
		}
//		cout<<endl;
		for(ll i=1;i<=m;i++) ans^=(i*Ans[i]);
		cout<<ans<<endl;
	}
	return 0;
}
