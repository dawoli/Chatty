#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+9;
ll T,n,k,a[N]; 
void FIO(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
}
inline bool clr(ll x){
	return k&(1<<(n-x));
} 
int main(){
	ios::sync_with_stdio(false);
	FIO();
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++)cin>>a[i];	
		ll ans=0;
		for(k=0;k<(1<<n);k++){
			ll res=0;
			for(ll i=1;i<=n;i++){
				ll pos=0;
				for(ll j=i-1;j>=1;j--){
					if(clr(j)==clr(i)){
						pos=j;break;
					}
				}
				if(pos!=0&&a[i]==a[pos])res+=a[i];
			}
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
