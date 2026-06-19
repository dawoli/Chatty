#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5009],p[5009];
bool vst[5009];
ll ans=0;
ll cnt,mx;
void check(ll e){
	cnt=0;
	mx=-1;
	for(int i=1;i<=e;i++){
		cnt+=a[p[i]];
		mx=max(mx,a[p[i]]);
	}
	if(cnt>mx*2) ans++;
}
void dfs(ll x,ll k){
	if(x==k+1){
		check(k);
		return;
    }
    if(k-x>n-p[x-1]) return;
    for(int i=p[x-1]+1;i<=n;i++){
    	if(!vst[i]){
    		vst[i]=1;
    		p[x]=i;
    		dfs(x+1,k);
    		vst[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++){
    	mx=-1;
    	dfs(1,i);
	}
	cout<<ans;
	return 0;
}
