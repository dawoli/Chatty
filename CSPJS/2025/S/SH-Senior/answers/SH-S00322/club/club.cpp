#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int T,n,a[N][5],cnt1,cnt2,cnt3,c1[N],c2[N],c3[N],cnt,d[N];
ll ans;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=cnt1;i++) c1[i]=0;
	for(int i=1;i<=cnt2;i++) c2[i]=0;
	for(int i=1;i<=cnt3;i++) c3[i]=0;
	for(int i=1;i<=cnt;i++) d[i]=0;
	cnt1=0,cnt2=0,cnt3=0,cnt=0,ans=0;
}

void delans()
{
	sort(d+1,d+cnt+1);
	for(int i=1;i<=cnt-n/2;i++) ans-=d[i];
}

void solve1()
{
	cnt=cnt1;
	for(int i=1;i<=cnt;i++) d[i]=min(a[c1[i]][1]-a[c1[i]][2],a[c1[i]][1]-a[c1[i]][3]);
	delans();
}

void solve2()
{
	cnt=cnt2;
	for(int i=1;i<=cnt;i++) d[i]=min(a[c2[i]][2]-a[c2[i]][1],a[c2[i]][2]-a[c2[i]][3]);
	delans();
}

void solve3()
{
	cnt=cnt3;
	for(int i=1;i<=cnt;i++) d[i]=min(a[c3[i]][3]-a[c3[i]][1],a[c3[i]][3]-a[c3[i]][2]);
	delans();
}

void solve()
{
	init();
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			ans+=a[i][1],cnt1++,c1[cnt1]=i;
			continue;
		}
		if(a[i][2]>=a[i][3]) ans+=a[i][2],cnt2++,c2[cnt2]=i;
		else ans+=a[i][3],cnt3++,c3[cnt3]=i;
	}
	if(cnt1>n/2) solve1();
	if(cnt2>n/2) solve2();
	if(cnt3>n/2) solve3();
	cout<<ans<<endl;
}

int main()
	{
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	return 0;
	}
