#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define N 110000
int t,n,a[N][4],ans;
vector<int> c[4];
inline void solve(){
	cin>>n;
	ans=0;
	c[1].clear();
	c[2].clear();
	c[3].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		int p=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==p){
			c[1].pb(a[i][1]-max(a[i][2],a[i][3]));
		}
		else if(a[i][2]==p){
			c[2].pb(a[i][2]-max(a[i][1],a[i][3]));
		}
		else{
			c[3].pb(a[i][3]-max(a[i][1],a[i][2]));
		}
		ans+=p;
	}
	for(int i=1;i<=3;i++){
		if(c[i].size()>=n/2+1){
			sort(c[i].begin(),c[i].end(),greater<int>());
			for(int j=n/2;j<c[i].size();j++){
				ans-=c[i][j];
			}
		}
	}
	cout<<ans<<'\n';
	return ;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
