#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int N=100005;
int _,n,a[N][5],ans,nw,cnt[5];
pii b[N];
bool cmp(pii a,pii b)
{
	return a.fi>b.fi;
}
void calc()
{
	nw=0;
	for(int i=1;i<=n;i++)
	{
		nw+=a[i][1];
		if(a[i][2]>=a[i][3]) b[i]=mkp(a[i][2]-a[i][1],2);
		else b[i]=mkp(a[i][3]-a[i][1],3);
	}
	sort(b+1,b+n+1,cmp);
	memset(cnt,0,sizeof(cnt));
	cnt[1]=n;
	for(int i=1;i<=n;i++)
	{
		nw+=b[i].fi,cnt[b[i].se]++,cnt[1]--;
		if(cnt[1]<=n/2&&cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) ans=max(ans,nw);
	}
	return;
}
void solve()
{
	ans=0,nw=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	calc();
	for(int i=1;i<=n;i++) swap(a[i][1],a[i][2]);
	calc();
	for(int i=1;i<=n;i++) swap(a[i][1],a[i][3]);
	calc();
	cout<<ans<<'\n';
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while(_--) solve();
	return 0;
}
