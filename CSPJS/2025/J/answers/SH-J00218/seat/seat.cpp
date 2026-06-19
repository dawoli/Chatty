#include<bits/stdc++.h> 
using namespace std;
int a[10000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,t,tt;
	cin>>n>>m;
	cin>>t;
	a[1]=t;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			tt=n*m-i+1;
		}	
	}
	int x,y;
	x=tt/(2*n);x*=2;
	if(tt%(2*n)<=n){
		x+=1;
		y=tt%(2*n);
	}
	else{
		x+=2;
		y=tt%(x*n)-n;
		y=n-y+1; }
	cout<<x<<" "<<y;
	return 0;
}
