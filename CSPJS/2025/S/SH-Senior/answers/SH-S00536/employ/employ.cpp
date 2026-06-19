#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const ll N=509;
ll a[N],c[N],p[N];
const ll MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(ll i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		for(ll i=1;i<=n;i++) p[i]=i;
		ll cnt=0;
		do{
			ll ans=0,t=0;
			for(ll i=1;i<=n;i++){
				if(t>=c[p[i]]){t++;continue;}
				t+=(a[i]==0);
				if(t<c[p[i]]&&a[i]==1) ans++;
			}
			if(ans>=m) cnt++;
		}while(next_permutation(p+1,p+1+n));
		cout<<cnt<<endl;
	} 
	return 0;
}
