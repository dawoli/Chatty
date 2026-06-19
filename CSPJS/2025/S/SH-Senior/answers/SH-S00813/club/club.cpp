#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll maxn=100009;
const ll inf=1e15;
ll n,nowi,a[maxn][4],id[maxn][4],cnt[4];
ll srt[maxn];
bool cmp(const ll&x,const ll&y){
	return a[nowi][x]>a[nowi][y];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T-->0){
		cin>>n;
		rep(i,1,n)	cin>>a[i][0]>>a[i][1]>>a[i][2];
		fill(cnt,cnt+3,0);
		ll sum=0;
		rep(i,1,n){
			nowi=i;
			rep(j,0,2)	id[i][j]=j;
			sort(id[i],id[i]+3,cmp);
			sum+=a[i][id[i][0]];
			cnt[id[i][0]]++;
		}
		ll mxid=max_element(cnt,cnt+3)-cnt;
		if(cnt[mxid]<=n/2){
			cout<<sum<<'\n';
			continue;
		}
		ll m=0;
		rep(i,1,n){
			if(id[i][0]!=mxid)	continue;
			m++;
			srt[m]=a[i][id[i][0]]-a[i][id[i][1]];
		}
		sort(srt+1,srt+1+m);
		rep(i,1,cnt[mxid]-n/2)	sum-=srt[i];
		cout<<sum<<'\n';
	}
	return 0;
}
