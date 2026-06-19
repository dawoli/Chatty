#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=1e5+10,N1=210;
ll t,n,a[N][3],dp[N1/2][N1/2][N1/2],bnd,tmp[N];
struct k
{
	ll a,b;
};
vector<k>tmp2,tmp3,tmp4;
bool vis[N];
void solve1()
{
	memset(dp,0,sizeof(dp));
	for(ll t=1;t<=n;++t)for(ll i=min(bnd,t);i>=0;--i)for(ll j=min(bnd,t-i);j>=0;--j)for(ll k=min(bnd,t-i-j);k>=0;--k)
	{
		if(i+j+k>t)continue;
		if(i>0)dp[i][j][k]=max(dp[i-1][j][k]+a[t][0],dp[i][j][k]);
		if(j>0)dp[i][j][k]=max(dp[i][j-1][k]+a[t][1],dp[i][j][k]);
		if(k>0)dp[i][j][k]=max(dp[i][j][k-1]+a[t][2],dp[i][j][k]);
//		printf("dp[%lld][%lld][%lld]=%lld\n",i,j,k,dp[i][j][k]);
	}
	ll ans=0;
	for(ll i=0;i<=bnd;++i)for(ll j=bnd-i;j<=bnd&&j<=n-i;++j)ans=max(ans,dp[i][j][n-i-j]);
	printf("%lld\n",ans);
}
void solve2()
{
	for(ll i=1;i<=n;++i)tmp[i]=a[i][0];
	sort(tmp+1,tmp+1+n);
	ll ans=0;
	for(ll i=n;i>n/2;--i)ans+=tmp[i];
	printf("%lld\n",ans);
}
void solve3(ll sumb)
{
	for(ll i=1;i<=n;++i)tmp[i]=a[i][0]-a[i][1];
	sort(tmp+1,tmp+1+n);
	for(ll i=n;i>n/2;--i)sumb+=tmp[i];
	printf("%lld\n",sumb);
}
bool cmp1(const k& a,const k& b){return a.a>b.a;}
bool cmp2(const k& a,const k& b){return a.b>b.b;}
void solve4(ll sumc)
{
	tmp2.resize(n);
	for(ll i=1;i<=n;++i)printf("%lld %lld %lld\n",a[i][0],a[i][1],a[i][2]);
	puts("");
	for(ll i=1;i<=n;++i)tmp2[i-1].a=a[i][0]-a[i][2],tmp2[i-1].b=a[i][1]-a[i][2];
	for(auto i:tmp2)printf("%lld %lld\n",i.a,i.b);
	puts("--------");
	sort(tmp2.begin(),tmp2.end(),cmp1);
	ll acnt=0,cnt=0,bcnt=0;
	memset(vis,0,sizeof(vis));
	for(auto i:tmp2)printf("%lld %lld\n",i.a,i.b);
	puts("--------");
	for(ll i=0;i<n;++i)
	{
		if(acnt>=bnd)break;
		if(tmp2[i].a<0)break;
		if(tmp2[i].a>tmp2[i].b)sumc+=tmp2[i].a,vis[i]=1,++acnt;
	}
	tmp3.resize(n-acnt),cnt=0;
	for(ll i=0;i<n;++i)if(!vis[i])tmp3[cnt++]=tmp2[i];
	sort(tmp3.begin(),tmp3.end(),cmp2);
	for(auto i:tmp3)printf("%lld %lld\n",i.a,i.b);
	puts("--------");
	memset(vis,0,sizeof(vis));
	for(ll i=0;i<cnt;++i)
	{
		if(bcnt>=bnd)break;
		if(tmp3[i].b<0)break;
		if(tmp3[i].b>tmp3[i].a)sumc+=tmp3[i].b,vis[i]=1,++bcnt;
	}
	tmp4.resize(cnt-bcnt),cnt=0;
	for(ll i=0;i<tmp3.size();++i)if(!vis[i])tmp4[cnt++]=tmp3[i];
	memset(vis,0,sizeof(vis));
	for(auto i:tmp4)printf("%lld %lld\n",i.a,i.b);
	puts("--------");
	for(ll i=0;i<cnt;++i)
	{
		if(tmp4[i].a>max(0ll,tmp4[i].b)&&acnt<bnd)++acnt,sumc+=tmp4[i].a,vis[i]=1;
		if(tmp4[i].b>max(0ll,tmp4[i].a)&&bcnt<bnd)++bcnt,sumc+=tmp4[i].b,vis[i]=1;
	}
	for(ll i=0;i<cnt;++i)if(!vis[i]&&tmp4[i].a==tmp4[i].b&&tmp4[i].a>0)
	{
		if(acnt<bnd)++acnt,sumc+=tmp4[i].a;
		else ++acnt,sumc+=tmp4[i].b;
	}
	printf("%lld\n",sumc);
}
void solve()
{
	scanf("%lld",&n),bnd=n/2;
	memset(a,0,sizeof(a));
	ll a2=0,a3=0;
	for(ll i=1;i<=n;++i)scanf("%lld %lld %lld",a[i],a[i]+1,a[i]+2),a2+=a[i][1],a3+=a[i][2];
	if(a2==0&&a3==0)solve2();
	else if(a3==0)solve3(a2);
	else if(n<=30)solve1();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)solve();
	return 0;
}

