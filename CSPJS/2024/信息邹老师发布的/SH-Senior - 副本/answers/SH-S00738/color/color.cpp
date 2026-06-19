#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+9;
ll T,n,a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=0;i<n;i++) cin>>a[i];
		ll ans=0;
		for(ll i=0;i<(1LL<<n);i++){
			ll lst0=-1,lst1=-1,sum=0;
			for(ll j=0;j<n;j++)
				if(i&(1LL<<j)){
					if(lst1!=-1&&a[lst1]==a[j]) sum+=a[j];
					lst1=j;
				}else{
					if(lst0!=-1&&a[lst0]==a[j]) sum+=a[j];
					lst0=j;
				}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
