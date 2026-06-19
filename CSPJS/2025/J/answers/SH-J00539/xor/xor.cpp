#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
const ll INF=1e9;
ll num[N];
bool ok[N];
ll n,k,ans;
ll findid(ll id){
	for(ll i=id;i<n;i++){
		if(num[id]!=INF)
		return i;
	}
	return -1;
}
void solve(ll now,ll cnt){
	ok[now]=true;
	if(cnt==k){
		ans++;
		ok[now]=false;
		return;
	}
	else if(now+1<n&&num[now+1]!=INF&&num[now]!=INF){
		cnt=cnt^(num[now+1]);
		solve(now+1,cnt);
	}
	else if(findid(now+1)!=-1){
		solve(findid(now+1),num[findid(now+1)]);
	}
	else {
		ok[now]=false;
		return;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>num[i];
		if(num[i]==k){
			ans++;
			num[i]=INF;
		}
	}
	fill(ok,ok+n,false);
	solve(0,num[0]);
	cout<<ans<<endl;
	return 0;
}
