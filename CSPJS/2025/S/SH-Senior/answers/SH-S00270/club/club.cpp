#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n;
ll a[100005][3];
struct node{
	ll val;
	ll times[3]={0,0,0};
}dp[100005][3];
void solve(){
	memset(dp,0,sizeof(dp));
	cin>>n;
	for (ll i=1;i<=n;i++){
		for (ll j=0;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for (ll i=0;i<=n;i++){
		for (ll j=0;j<=2;j++){
			for (ll k=0;k<=2;k++){
				if (dp[i][j].times[k]<n/2){
					if (dp[i][j].val+a[i+1][k]>dp[i+1][k].val){
						dp[i+1][k].val=max(dp[i+1][k].val,dp[i][j].val+a[i+1][k]);
						for (ll q=0;q<=2;q++){
							dp[i+1][k].times[q]=dp[i][j].times[q];
						}
						dp[i+1][k].times[k]++;
					}
				}
			}
		}
	}
	
	cout<<max(dp[n][0].val,max(dp[n][1].val,dp[n][2].val))<<endl;
}
ll ansBF=0;
void dfs(ll cur,ll xcnt,ll ycnt,ll zcnt,ll ansval){
	if (cur==n+1){
		ansBF=max(ansBF,ansval);
		return;
	}
	if (xcnt<n/2) dfs(cur+1,xcnt+1,ycnt,zcnt,ansval+a[cur][0]);
	if (ycnt<n/2) dfs(cur+1,xcnt,ycnt+1,zcnt,ansval+a[cur][1]);
	if (zcnt<n/2) dfs(cur+1,xcnt,ycnt,zcnt+1,ansval+a[cur][2]);
	
}
void solveBF(){
	ansBF=0;
	dfs(1,0,0,0,0);
	cout<<ansBF<<endl;
}
multiset<ll>st;
void solve_A(){
	ll ansq=0;
	for (ll i=1;i<=n;i++){
		st.insert(a[i][0]);
	}
	ll cnt=0;
	for (auto it=st.begin();it!=st.end();it++){
		cnt++;
		if (cnt>n/2 && cnt<=n)ansq+=(*it);
	}
	cout<<ansq<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--) {
		cin>>n;
		for (ll i=1;i<=n;i++) for (ll j=0;j<=2;j++) cin>>a[i][j];
		bool determine_A=true;
		if (n<=30){
			solveBF();
			continue;
		}
		for (ll i=1;i<=n;i++){
			if (a[i][1]!=0 or a[i][2]!=0){
				determine_A=false;
				break;
			}
		}
		if (determine_A){
			solve_A();
			continue;
		}
		solve();
	}
	return 0;
}
