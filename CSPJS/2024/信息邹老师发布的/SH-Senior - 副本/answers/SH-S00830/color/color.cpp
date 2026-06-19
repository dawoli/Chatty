#define I using
#define love namespace
#define Poncirus_forever std

	I love Poncirus_forever;

#include<cstdio>
#include<cstring>
#define ll long long
#define in(x) scanf("%lld",&x)
#define cn continue
const ll N=1e6+5;
ll T,n,h1,h2,ans,res,a[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	in(T);
	while(T--)
	{
		h1=h2=ans=res=0;
		memset(a,0,sizeof a);
		in(n);
		for(ll i=1;i<=n;i++)
		{
			in(a[i]);
			if(a[i]==a[i-1]) ans+=a[i],i--,n--;
		}
		for(ll x=0;x<(1<<n);x++)
		{
			ll xl=x;
//			printf("%lld ",xl);
			ll num=0,hd[2]={0,0};
			for(ll i=1;i<=n;i++)
			{
				ll w=xl&1;
				if(a[i]==hd[w]) num+=a[i];
				hd[w]=a[i];
				xl>>=1;
			}
//			printf("%lld\n",num);
			if(num>res) res=num;
		}
		printf("%d\n",res+ans);
	}
	return 0;
}
/*

*/

