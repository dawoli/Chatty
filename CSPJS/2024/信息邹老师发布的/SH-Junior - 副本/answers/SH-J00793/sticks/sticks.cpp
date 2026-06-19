#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000009;
ll calc(ll x){
	if(x%7==0) return x/7;
	return x/7+1;
}
ll cst[15]={6,2,5,5,4,5,6,3,7,6};
ll f(ll l,ll r,ll lmt){
	ll res=114;
	for(ll i=0;i<=9;i++){
		if(i==0){
			if(!lmt&&l<=cst[i]&&cst[i]<=r) res=min(res,i);
		}
		else if(l<=cst[i]&&cst[i]<=r)res=min(res,i);
	}
	return res;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	if(n==1){
    		cout<<-1<<endl;
    		continue;
		}
		else{
			ll digits=calc(n);
			for(ll i=1;i<=digits;i++){
				ll l=n-7*(digits-i);
				ll r=n-2*(digits-i);
				ll now=f(l,r,i==1);
				cout<<now;
				n-=cst[now];
			}
			cout<<endl;
		}
	}
    return 0;
}
