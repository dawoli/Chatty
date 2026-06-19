#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][4];
int cnt[4],ch[N];
int f[N];
ll cal(int x){
	int y=x%3+1;
	int z=(x+1)%3+1;
	ll ans=0,k=cnt[x]-n/2,len=0;
	for(int i=1;i<=n;i++){
		if(ch[i]!=x) continue;
		ll l=a[i][x]-a[i][y],r=a[i][x]-a[i][z];
		f[++len]=min(l,r);
	}
	sort(f+1,f+len+1);
	for(int i=1;i<=k;i++) ans+=f[i];
	return ans;
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	memset(a,0,sizeof(a));
	memset(ch,0,sizeof(ch));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	int lim=n/2;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) cnt[1]++,ans+=a[i][1],ch[i]=1;
		else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) cnt[2]++,ans+=a[i][2],ch[i]=2;
		else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]) cnt[3]++,ans+=a[i][3],ch[i]=3;
	}
	if(cnt[1]<=lim && cnt[2]<=lim && cnt[3]<=lim) cout<<ans<<"\n";
	else if(cnt[1]>lim) cout<<ans-cal(1)<<"\n";
	else if(cnt[2]>lim) cout<<ans-cal(2)<<"\n";
	else if(cnt[3]>lim) cout<<ans-cal(3)<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


147325
*/ 
