#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],st[15][15],x=1,y=1,ansx,ansy;
bool zt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ansx=x;
			ansy=y;
			break;
		}
		st[x][y]=a[i];
		if(zt){
			x--;
		}
		else{
			x++;
		}
		if(x>m){
			x--;
			zt=1;
			y++;
		}
		if(x<1){
			x++;
			zt=0;
			y++;
		}
	}
	cout<<ansy<<' '<<ansx;
	return 0;
}
