#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500009],s,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s=a[i];
		for(ll j=i+1;j<=n;j++){
			s+=a[j];
			for(ll k=j+1;k<=n;k++){
				s+=a[k];
				if(s>a[k]*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
