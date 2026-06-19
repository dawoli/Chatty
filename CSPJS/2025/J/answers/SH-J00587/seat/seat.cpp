#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,sr,ar,a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	
		cin>>a[i];
	ar=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ar) sr=n*m-i+1;
	}
	c=ceil(sr*1.0/n);
	if(c%2==1){
		r=sr%n;
		if(r==0) r=n;
	}
	else{
		r=n+1-(sr%n);
		if(r==n+1) r=1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
} 
