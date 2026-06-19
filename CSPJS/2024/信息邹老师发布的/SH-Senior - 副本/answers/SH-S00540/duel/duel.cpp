#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,cnt[N],rem;
void solve(){
	cin>>n;
	for(int i=1,r;i<=n;i++)cin>>r,++cnt[r];
	for(int i=1;i<N;i++)if(cnt[i])rem=max(rem,cnt[i]);
	cout<<rem<<'\n';
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;//cin>>T;
	while(T--)solve();
	return 0;
}