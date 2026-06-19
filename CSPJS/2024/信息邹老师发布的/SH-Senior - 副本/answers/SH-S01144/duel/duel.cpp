#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ct;long long ans;
map<int,int> mp;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=0,x; i<n; i++)
		scanf("%d",&x),mp[x]++;
	for (pair<int,int> p:mp)
		a[++ct]=p.second;
	ans=a[1];
	for (int i=2; i<=ct; i++) {
		long long sub=min(ans,1ll*a[i]);
		ans-=min(ans,1ll*a[i]),ans+=a[i];
	}
	printf("%lld",ans);
	return 0;
}
