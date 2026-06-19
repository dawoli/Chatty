#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,r,y=1,y1;
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>r){
			y++;
		}
	}
	int x1=y/n+min(1,y%n);
	if(x1%2==1){
		y1=y%n;
		if(y1==0){
			y1=n;
		}
	}
	else{
		int mid=m/2+min(1,m%2);
		y1=y%n;
		if(y1<mid){
			y1=n-y1;
		}
		else{
			y1=n-y1+1;
		}
	}
	cout<<x1<<" "<<y1;
	return 0;
} 
