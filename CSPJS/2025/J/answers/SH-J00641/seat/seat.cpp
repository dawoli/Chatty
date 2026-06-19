#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10003]={},r,ans;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			r=n*m-i;
			break;
		}
	}
	int x,y;
	if(r%n==0){
		y=r/n;
	}
	else y=r/n+1;
	if(y%2==1){
		if(r%n==0){
			x=n;
		}
		else{
			x=r%n;
		}
	}
	else{
		if(r%n==0){
			x=1;
		}
		else{
			x=n-r%n+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
