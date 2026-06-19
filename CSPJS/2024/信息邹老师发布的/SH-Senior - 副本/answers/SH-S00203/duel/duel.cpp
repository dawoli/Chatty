#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
ll n,a[100005],t,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n)scanf("%lld",&t),a[t]++;
	rep(i,1,100000){
		ans = max(ans,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
