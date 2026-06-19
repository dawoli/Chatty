#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,s[15]= {6,2,5,5,4,5,6,3,7,6},ans;
void solve7() {
	for(ll i=1; i<=n/7; ++i) cout<<8;
}
void solve71() {
	cout<<"16";
	for(ll i=1; i<n/7; ++i) cout<<8;
}
void dfs(ll stp,ll cnt,ll num) {
	if(ans<num) return;
	if(cnt==n) {
		ans=num;
		return;
	}
	if(cnt>n) return;
	for(ll i=0; i<9; ++i) {
		if(i==3 || i==5) continue;
		if(stp==1 && !i) continue;
		dfs(stp+1,cnt+s[i],num*10+i);
	}
}
void solve50() {
	ans=9e18;
	dfs(1,0,0);
	if(ans==9e18) cout<<-1;
	else cout<<ans;
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n==1) cout<<-1;
		else if(n%7==0) solve7();
		else if(n%7==1) solve71();
		else solve50();
		cout<<"\n";
	}
	return 0;
}
