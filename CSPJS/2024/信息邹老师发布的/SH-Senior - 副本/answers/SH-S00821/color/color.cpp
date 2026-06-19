#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[19];
ll score(ll Code){
	ll anoCode=Code,sum=0;
	ll clr[19];
	memset(clr,0,sizeof(clr));
	for(ll i=1;i<=n;i++){
		if(anoCode%2==1) clr[i]=1;
		anoCode/=2;
	}
	for(ll i=1;i<=n;i++){
		ll ci=0;
		for(ll j=i-1;j>=1;j--){
			if(clr[i]==clr[j]){
				if(a[i]==a[j]) ci=a[i];
				break;
			}
		}
		sum+=ci;
	}
	return sum;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ll ans=0;
		for(ll i=0;i<(1<<n)-1;i++){
			ans=max(ans,score(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}
