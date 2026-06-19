#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[109],zs,rf,pm,c,r,ms,b[19][19];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(j%2==1){
				b[i][j]=j*n-(n-i);
			}
			else{
				b[i][j]=j*n-(i-1);
			}
		}
	}
	zs=n*m;
	for(ll i=1;i<=zs;i++){
		cin>>a[i];
	}
	rf=a[1];
	sort(a+1,a+zs+1);
	for(ll i=1;i<=zs;i++){
		if(a[i]==rf){
			pm=zs+1-i;
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(pm==b[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
