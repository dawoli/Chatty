#include <bits/stdc++.h>
using namespace std;
bool a[101];
int n,m,a_r,a_now,i,r=1,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a_now;
		if(i==1) a_r=a_now;
		a[a_now]=1;
	}
	for(i=100;i>=a_r;i--){
		if(i==a_r) cout<<c<<' '<<r;
		if(a[i]){
			if(c%2==1){
				if(r==n) c++;
				else r++;
			}
			else{
				if(r==1) c++;
				else r--;
			}
		}
	}
	return 0;
}
