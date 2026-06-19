#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[114514],arr[114514],ans;
bool check(ll m){
	ll sum = 0,mx = 0;
	for(ll i = 1;i <= m;i++) mx = max(mx,a[arr[i]]),sum+=a[arr[i]];
	if(sum > mx * 2) return 1;
	else return 0;
}
void combination(ll m,ll t){
	if(t == m+1){
		if(check(m)) ans++;
		return ;
	}
	for(ll i = arr[t-1]+1;i <= n;i++){
		arr[t] = i;
		combination(m,t+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i = 1;i <= n;i++) cin>>a[i];
	for(ll i = 3;i <= n;i++) combination(i,1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
