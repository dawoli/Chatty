#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll x[N],cnt[N],ans;
ll n,cntnum;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i],cnt[x[i]]++;
	ans=n;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		if(x[i]==x[i-1]) continue;
		ll ese=min(cnt[x[i]],cntnum);
		ans-=ese;
		cntnum+=(cnt[x[i]]-ese);
	} 
	cout<<ans;
	return 0;
}
