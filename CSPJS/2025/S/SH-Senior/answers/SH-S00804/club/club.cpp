#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct NODE{
	ll val,num,team;
};
ll t,n;
NODE a[300005];
inline bool cmp(NODE a,NODE b){
	return (a.val > b.val);
}
inline ll mid(ll x,ll y,ll z){
	ll arr[3] = {x,y,z};
	sort(arr,arr+3);
	return arr[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t--){
		ll ans = 0;
		cin>>n;
		for(ll i = 1;i <= n;i++){
			ll o = 3*i-2;
			ll p = o+1;
			ll q = p+1;
			cin>>a[o].val>>a[p].val>>a[q].val;
			a[o].num = i,a[q].num = i,a[p].num = i;
			a[o].team = 1,a[q].team = 3,a[p].team = 2;
			ll md = mid(a[o].val,a[p].val,a[q].val);
			a[p].val-=md,a[o].val-=md,a[q].val-=md;
			ans+=md;
		}
		sort(a+1,a+1+3*n,cmp);
		bool vis[100005] = {0};
		ll sum[5] = {0};
		ll cnt = 0;
		for(ll i = 1;i <= 3*n;i++){
			if(!vis[a[i].num] && sum[a[i].team] < n/2){
				vis[a[i].num] = 1;
				sum[a[i].team]++;
				ans+=a[i].val;
				cnt++;
			}
			if(cnt == n) break;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
