#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],jilu,x,y; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for (int i=1;i<n*m;++i){
		cin>>a[i];
	} 
	jilu=a[0];
	sort(a,a+n*m+1);
	for (int i=0;i<n*m;++i){
		if (a[i]==jilu){
			jilu=n*m-i+1;
			break;
		}
	}
	if (jilu%n==0){
		x=jilu/n;
	}else{
		x=jilu/n+1;
	}
	if (x%2==0){
		if (jilu%n==0) y=1;
		else y=n-jilu%n+1;
	}else{
		if (jilu%n==0) y=n;
		else y=jilu%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
