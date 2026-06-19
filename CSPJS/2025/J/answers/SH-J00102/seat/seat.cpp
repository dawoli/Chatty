#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int t=1;
	int k,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[1]<a[i]){
			t++;
		}
	}
	if(t%n==0){
		k=t/n;
	}
	else{
		k=t/n+1;
	}
	if(t%(2*n)<n){
		h=t-(k-1)*n;
	}
	else{
		h=k*n-t+1;
	}
	cout<<k<<" "<<h;
	return 0;
}
