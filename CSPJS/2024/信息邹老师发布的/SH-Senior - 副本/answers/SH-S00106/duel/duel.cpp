#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],now;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	now=1;
	for(int i=1;i<=n;i++){
		now=upper_bound(a+now+1,a+n+1,a[i])-a;
		if(now==n+1){
			printf("%lld",n-i+1);
			return 0;
		}
	}
	return 0;
} 
