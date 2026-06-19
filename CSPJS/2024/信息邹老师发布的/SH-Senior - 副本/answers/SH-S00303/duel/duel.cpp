#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int n,x[N],cnt[N];
bool d[N];
multiset<int> ms;
multiset<int>::iterator it;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]); cnt[x[i]]++;
		ms.insert(x[i]);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		if(cnt[x[i]]==0) continue;
		it=ms.lower_bound(x[i]);
		if(it==ms.begin()) continue;
		it--;
		cnt[*it]--; ms.erase(it);
	}
	int sum=0;
	for(int i=1;i<=1e5;i++) sum+=cnt[i];
	printf("%lld",sum);
	return 0;
}
