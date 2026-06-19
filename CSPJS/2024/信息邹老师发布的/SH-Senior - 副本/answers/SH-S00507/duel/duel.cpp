#include<bits/stdc++.h>
using namespace std;
int n;
const int N=100009;
int r[N],bin[N];
bool isCondition1(){
	for(int i=1;i<=n;i++)
		if(r[i]>2) return 0;
	return 1; 
}
void solve1(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
		if(r[i]==1) cnt1++;
		else cnt2++;
	cout<<max(cnt1,cnt2)<<endl;
}
void solve(){
	for(int i=1;i<=n;i++) bin[r[i]]++;
	int maxs=0;
	for(int i=1;i<=n;i++) maxs=max(maxs,r[i]);
	int ans=0;
	for(int i=1;i<=maxs;i++)
		ans=max(ans,bin[r[i]]);
	cout<<ans<<endl;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	if(isCondition1()) solve1();
	else solve();
	return 0;
}
