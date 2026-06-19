#include<bits/stdc++.h>
#define N 100009
#define INF 1e18
using namespace std;
typedef long long ll;
ll n,a[N],mx=0;
void input(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
}
void solve12(){
	ll cnt1=0,cnt2=0;
	for(ll i=1;i<=n;i++)
		if(a[i]==1) cnt1++;
	cnt2=n-cnt1;
	if(cnt2>cnt1) printf("%lld",cnt2);
	else printf("%lld",cnt1);
//	printf(" 1384123-43821");
}
void solveR(){
	sort(a+1,a+n+1);
	a[n+1]=INF;
	ll j=1,ans=n;
	for(ll i=1;i<=n&&j<=n;i++){
		while(a[j]<=a[i]) j++;
		if(j>n) break;
		ans--; j++;
	}
	printf("%lld",ans);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input();
	if(mx<=2)
		solve12();
	else
		solveR();
	return 0;
}


