#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct NODE{
	ll l,r;
}b[1005];
ll n,k,a[514514],s[514514],dp[514514],t,mx;
ll yihuo(ll a,ll b){
	ll t = 0,arr[100] = {0},arr1[100] = {0},arr2[100] = {0};
	while(a || b){
		arr[++t] = a % 2,arr1[t] = b % 2;
		a/=2,b/=2;
		arr[t] = (arr[t] != arr1[t]);
	}
	ll sum = 0;
	for(ll i = t;i >= 1;i--) sum = sum * 2 + arr[i];
	return sum;
}
bool cmp(NODE a,NODE b){
	return (a.r < b.r);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1;i <= n;i++) cin>>a[i];
	for(ll i = 1;i <= n;i++) s[i] = yihuo(s[i-1],a[i]);
	for(ll i = 1;i <= n;i++){
		for(ll j = i;j <= n;j++){
			if(yihuo(s[j],s[i-1]) == k){
				b[++t] = NODE{i,j};
				break;
			}
		}
	}
	sort(b+1,b+1+t,cmp);
	for(ll i = 1;i <= t;i++){
		for(ll j = n;j >= b[i].r;j--){
			dp[j] = max(dp[j],dp[b[i].l-1LL]+1LL);
			mx = max(mx,dp[j]);
		}
	}
	cout<<mx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
