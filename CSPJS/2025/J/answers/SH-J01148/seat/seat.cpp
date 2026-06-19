#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0,zz=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) z=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			zz=n*m-i+1;
			break;
		}
	}
	if(zz%n==0){
		c=zz/n;
		if(c%2==1){
			r=n;
		}
		else{
			r=1;
		}
	}
	else {
		c=zz/n+1;
	    if(c%2==1){
		    r=zz%n;
	    }
		else{
	    	r=n-zz%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
