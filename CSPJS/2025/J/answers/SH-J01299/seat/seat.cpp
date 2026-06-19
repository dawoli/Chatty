#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
ll n,m,xr,xrp;
ll ansx,ansy;
bool cmp(ll a,ll b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++) cin>>a[i];
	xrp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xrp){
			xr=i;
			break;
		}
	}
	if(xr%n==0){
		ansx=xr/n;
		if(ansx%2==0) ansy=1;
		else ansy=n;
	}
	else{
		ansx=xr/n+1;
		if(ansx%2==1) ansy=xr%n;
		else ansy=n-xr%n+1;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
