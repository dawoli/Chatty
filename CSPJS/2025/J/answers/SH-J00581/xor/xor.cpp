#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
ll n;
ll a[500010];
ll sum[500010];
ll ans,tmp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum[i+1]=sum[i]^a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=tmp;j<=i;j++){
			if (a[i]==0){
				break;
			}
			if (a[i]==a[i-1] && i-1!=tmp && i!=tmp){
				break;
			}
			if (i==j){
				if (a[i]==k){
					
					ans++;
					tmp=i+1;
					break;
				}
			}
			else {
				ll ttt=sum[j]^sum[i+1];
				if (ttt==k){
					
					ans++;
					tmp=i+1;
					break;
				}
			}
			
		}
	}
	cout<<ans;
}
