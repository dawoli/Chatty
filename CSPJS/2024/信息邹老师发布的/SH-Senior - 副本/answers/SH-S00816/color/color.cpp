#include<bits/stdc++.h>
#define N 1003
using namespace std;
typedef long long ll;
// ~20, O(n*n*(2^n))
ll n,a[N];
void input(){
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)
		scanf("%d",&a[i]);
}
void solve1_4(){
	bool col[N];ll ans=0;
	memset(col,0,sizeof(col));
	for(ll ptn=1;ptn<=(1<<n);ptn++){
		ll C=0;
		for(ll i=1;i<=n;i++)
			col[i]=(((1<<i)|ptn)==ptn);
		for(ll i=1;i<=n;i++)
			for(ll j=i-1;j>=1;j--)
				if(col[i]==col[j]){
					if(a[i]==a[j])C+=a[i];
					break;
				}
		ans=max(C,ans);
	}
	printf("%lld\n",ans);
}
void solve(){
	printf("0\n");
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		input();
		//solve();
		solve1_4();
	}
	fclose(stdin),fclose(stdout);
	return 0;
}

