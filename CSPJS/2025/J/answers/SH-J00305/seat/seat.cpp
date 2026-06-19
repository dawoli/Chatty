#include <bits/stdc++.h>
using namespace std;
int a[100+10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,cnt=0,ansx,ansy;
	double x,y;
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[0]<a[i]){
			cnt++;
		}
	}
	cnt++;
	x=(cnt+0.0)/n;
	ansx=x;
	if(x!=int(x)*1.0){
		ansx++;
	}
	y=cnt-n*(ansx-1);
	if(ansx%2==0){
		ansy=n-y+1;
	}else{
		ansy=y; 
	}
	cout<<ansx<<' '<<ansy;
	return 0;
}
