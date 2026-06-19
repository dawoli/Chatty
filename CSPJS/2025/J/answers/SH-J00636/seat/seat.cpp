#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,x0,y0,t,score,rank=0;
	cin>>x>>y;
	for(int i=1;i<=x*y;++i){
		cin>>t;
		if(i==1){
			score=t;
		}
		if(t>=score)rank++;
	}
	x0=1+(rank-1)/x;
	if(x0%2){
		y0=rank-x*(x0-1);
	}
	else{
		y0=1+x0*x-rank;
	}
	cout<<x0<<" "<<y0;
	return 0;
}
