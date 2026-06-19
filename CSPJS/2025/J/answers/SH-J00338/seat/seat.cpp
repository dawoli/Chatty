#include<bits/stdc++.h>
using namespace std;
bool cyd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[105],g,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+m*n+1,cyd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==g){
			g=i;
			break;
		}
	}
	if(g%n==0){
		c=g/n;
		if((c-1)%2==0) r=n;
		else r=1; 
	}
	else if(g%n==1){
		c=g/n+1;
		if((c-1)%2==0) r=1;
		else r=n;
	}
	else{
		c=g/n+1;
		if((c-1)%2==0) r=g%n;
		else r=m-g%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
