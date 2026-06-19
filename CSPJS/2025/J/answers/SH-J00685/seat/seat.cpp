#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
int n,m,a[N],c=1,r=1;

void solve(){
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1]){
			if(c%2==1){
				if(r!=n) r++;
				else c++;
			}
			else{
				if(r!=1) r--;
				else c++;
			}
		}
	}
	cout<<c<<' '<<r;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
