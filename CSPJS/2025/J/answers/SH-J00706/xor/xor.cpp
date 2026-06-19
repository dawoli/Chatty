#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500009],ans,zs;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		zs=a[i];
		for(ll j=i+1;j<=n;j++){
			zs=zs^a[j];
			if(zs==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
