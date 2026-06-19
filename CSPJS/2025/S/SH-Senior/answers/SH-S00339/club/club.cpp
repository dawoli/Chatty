#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N][3],cnt[5],maxn[N],maxn2[N],ans,t;
priority_queue<int> q[5];
void solve(){
	cin>>n; ans=0; cnt[0]=cnt[1]=cnt[2]=0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	for(int i=1;i<=n;++i){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>a[i][1]){
			if(a[i][2]>a[i][0]) maxn[i]=2;
			else maxn[i]=0;
		}else{
			if(a[i][2]>a[i][1]) maxn[i]=2;
			else maxn[i]=1;
		}
		if(maxn[i]==0){
			if(a[i][1]>a[i][2]) maxn2[i]=1;
			else maxn2[i]=2;
		}else if(maxn[i]==1){
			if(a[i][0]>a[i][2]) maxn2[i]=0;
			else maxn2[i]=2;
		}else{
			if(a[i][0]>a[i][1]) maxn2[i]=0;
			else maxn2[i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(cnt[maxn[i]]<n/2){
			ans+=a[i][maxn[i]];
			cnt[maxn[i]]++;
			q[maxn[i]].push(a[i][maxn2[i]]-a[i][maxn[i]]);
			continue;
		}
		t=q[maxn[i]].top();
		if(t+a[i][maxn[i]]>a[i][maxn2[i]]){
			ans+=t+a[i][maxn[i]];
			q[maxn[i]].pop();
			q[maxn[i]].push(a[i][maxn2[i]]-a[i][maxn[i]]);
		}else ans+=a[i][maxn2[i]];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}
