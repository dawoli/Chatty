#include<bits/stdc++.h>
#include<cmath>
#define mkp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn= 1e5+9 ;

int T,n;
int cnt[5];
ll ans;

int a[5][maxn];
void dfsBF(int dep,ll v)
{
	if(dep==n)
	{
		if(max(max(cnt[1],cnt[2]),cnt[3])<=n/2)
			ans=max(ans,v);
			
		return ;
	}
	
	for(int i=1;i<=3;++i)
	{
		++cnt[i];
		dfsBF(dep+1,v+a[i][dep+1]);
		--cnt[i];
	}
	
	return ;
}

void solveBF()
{
	dfsBF(0,0);
	printf("%lld\n",ans);
	
	return ;
} 

pii as[5][maxn];
int nS[5];

bool cmp1(pii &tmp1,pii &tmp2)
{
	return (tmp1.first-tmp1.second) > (tmp2.first-tmp2.second) ;
}

bool cmp2(pii &tmp1,pii &tmp2)
{
	return tmp1.first==tmp2.first ? tmp1.second<tmp2.second : tmp1.first>tmp2.first ;
}

void solve()
{
	for(int i=1;i<=n;++i)
	{
		int nmx=max(max(a[1][i],a[2][i]),a[3][i]);
		
		if(a[1][i]==nmx)
		{
			++cnt[1];
			as[1][++nS[1]]=mkp(nmx, max(a[2][i],a[3][i]) );
		}
		else if(a[2][i]==nmx)
		{
			++cnt[2];
			as[2][++nS[2]]=mkp(nmx, max(a[1][i],a[3][i]) );
		}
		else
		{
			++cnt[3];
			as[3][++nS[3]]=mkp(nmx, max(a[1][i],a[2][i]) );
		}
	}
	
	if( max(max(cnt[1],cnt[2]),cnt[3] )<=n/2 )
	{
		for(int nowi=1;nowi<=3;++nowi)
		for(int i=1;i<=nS[nowi];++i)
		{
			ans+=as[nowi][i].first;
		}
	}
	else
	{
		if(cnt[1]>=n/2)
		{
			sort(as[1]+1,as[1]+1+nS[1],cmp1);
			
			for(int i=1;i<=n/2;++i)
				ans+=as[1][i].first;
			for(int i=n/2+1;i<=nS[1];++i)
				ans+=as[1][i].second;
				
			for(int i=1;i<=nS[2];++i)
				ans+=as[2][i].first;
			for(int i=1;i<=nS[3];++i)
				ans+=as[3][i].first;
		}
		else if(cnt[2]>=n/2)
		{
			sort(as[2]+1,as[2]+1+nS[2],cmp1);
			
			for(int i=1;i<=n/2;++i)
				ans+=as[2][i].first;
			for(int i=n/2+1;i<=nS[2];++i)
				ans+=as[2][i].second;
				
			for(int i=1;i<=nS[1];++i)
				ans+=as[1][i].first;
			for(int i=1;i<=nS[3];++i)
				ans+=as[3][i].first;
		}
		else
		{
			sort(as[3]+1,as[3]+1+nS[3],cmp1);
			
			for(int i=1;i<=n/2;++i)
				ans+=as[3][i].first;
			for(int i=n/2+1;i<=nS[3];++i)
				ans+=as[3][i].second;
				
			for(int i=1;i<=nS[1];++i)
				ans+=as[1][i].first;
			for(int i=1;i<=nS[2];++i)
				ans+=as[2][i].first;
		}
	}
	
	printf("%lld\n",ans);
	return ;
}

void init()
{
	for(int i=0;i<=3;++i)
		cnt[i]=0;
	for(int i=0;i<=3;++i)
		nS[i]=0;
	ans=0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
		}
		
		if(n<=10)
			solveBF();
		else
			solve();
	}
	
	return 0;
}

