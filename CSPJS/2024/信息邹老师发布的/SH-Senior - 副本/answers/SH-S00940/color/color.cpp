#include<bits/stdc++.h>
#define INF 2e9
#define ll long long
using namespace std;
const ll N=2e5+5;
bool ok[N];
ll T,n,a[N],ans,pos,f[3][N];
ll Score(ll x,ll y){
	if(a[x]==a[y]) return a[x];
	return 0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		a[0]=ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=20000)
		{
			//f[i][j]表示1~i位,且与第i位不同色的最后一位为第j位的最大得分 
//			for(ll i=1;i<=n;i++)
//				for(ll j=0;j<i;j++)
//				{
//					f[i][j]=max(f[i][j],f[i-1][j]+Score(i,i-1));
//					f[i][i-1]=max(f[i][i-1],f[i-1][j]+Score(i,j));
//				}
			for(ll i=1;i<=n;i++)
				for(ll j=0;j<i;j++)
				{
					f[i&1][j]=max(f[i&1][j],f[i&1^1][j]+Score(i,i-1));
					f[i&1][i-1]=max(f[i&1][i-1],f[i&1^1][j]+Score(i,j));
				}
			for(ll i=0;i<n;i++) ans=max(ans,f[n&1][i]);
			printf("%lld\n",ans);
		}
		else
		{
			memset(ok,0,sizeof(ok));
			for(ll i=1;i<=n;i++)
				if(ok[a[i]]==0) ok[a[i]]=1;
				else{pos=i; break;}
			for(ll i=pos;i<=n;i++)
				for(ll j=0;j<i;j++)
				{
					f[i&1][j]=max(f[i&1][j],f[i&1^1][j]+Score(i,i-1));
					f[i&1][i-1]=max(f[i&1][i-1],f[i&1^1][j]+Score(i,j));
				}
			for(ll i=0;i<n;i++) ans=max(ans,f[n&1][i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
