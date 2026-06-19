#include<bits/stdc++.h>
#define MM 114514 
using namespace std;
typedef long long ll;
ll aa[MM],bb[MM],cc[MM],ans,dp[5009][5009],mm,t,n,maa,mbb;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mm=n/2;
		for(int i=1;i<=n;++i){
			cin>>aa[i]>>bb[i]>>cc[i];
		}
		for(ll i=1;i<=n;++i){
			maa=max(i,mm);
			for(ll ca=maa-1;ca>=0;--ca){
				mbb=i-ca;
				for(ll cb=mbb-1;cb>=0;--cb){
					if(ca<mm){
						dp[ca+1][cb]=max(dp[ca][cb]+aa[i],dp[ca+1][cb]);
						ans=max(ans,dp[ca+1][cb]);
					}
					if(cb<mm){
						dp[ca][cb+1]=max(dp[ca][cb]+bb[i],dp[ca][cb+1]);
						ans=max(ans,dp[ca][cb+1]);
					}
					if((i-ca-cb)<=mm){
						dp[ca][cb]+=cc[i];
						ans=max(ans,dp[ca][cb]);
					}
//					cout<<"ans "<<i<<" = "<<ans<<"\n"; 
				}
			}
		}
		cout<<ans<<"\n";
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<=n;++j){
				dp[i][j]=0;
			} 
		}
		ans=0;
	}
	return 0; 
}
