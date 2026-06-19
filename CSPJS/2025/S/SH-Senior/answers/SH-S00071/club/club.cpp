#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[101010][5];
priority_queue<pair<ll,pair<int,int>>>pq;
int cnt[5];
bool changed[101010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	ll ans=0;
	for(int p=1;p<=3;p++)
	{
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;i++) changed[i]=0;
		for(int j=1;j<=3;j++) cnt[j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) if(j!=p) pq.push(make_pair(a[i][j]-a[i][p],make_pair(i,j)));
		ll sum=0;
		cnt[p]=n;
		for(int i=1;i<=n;i++) sum+=a[i][p];
		while(!pq.empty())
		{
			auto tmp=pq.top();pq.pop();
			ll val=tmp.first;int pos1=tmp.second.first,pos2=tmp.second.second;
			if(changed[pos1]||cnt[pos2]+1>n/2) continue;
			if(val>=0||cnt[p]>n/2)
			{
				cnt[pos2]++,cnt[p]--;
				changed[pos1]=1;
				sum+=val;
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;cin>>t;
	while(t--) solve();
	return 0;
}

