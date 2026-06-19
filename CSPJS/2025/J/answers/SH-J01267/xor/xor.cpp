#include<bits/stdc++.h>
using namespace std;
int n,ans,sum,a[500009],lim,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	lim=n+109;
	for(int ub=n;ub>=1;ub--){
		for(int lb=1;lb<=ub;lb++){
			sum=a[lb];
			for(int i=lb+1;i<=ub;i++){
				sum=(sum xor a[i]);
			}
			if(sum==k){
				if(ub<lim){
					ans++;
					lim=lb;
				}
				cout<<"[ "<<lb<<" , "<<ub<<" ]"<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
