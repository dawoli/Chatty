#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[10009];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1);
	int pw;
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			pw=i;
			break;
		}
	}
	pw=n*m-pw+1;
	int k=pw/(2*n);
	int r=pw-k*2*n;
	if(r==0){
		r=2*n;
		k--;
	}
	if(r<=n){
		cout<<2*k+1<<" "<<r;
	}
	if(r>n){
		cout<<2*k+2<<" "<<2*n-r+1;
	}
	return 0;
}
