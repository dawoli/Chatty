#include <bits/stdc++.h>
using namespace std;
char dt[1005][1005];
bool tag[1005][1005];
int n,m;
bool cwz(int axx,int axy){
	if(1<=axx<=n){
		if(1<=axy<=m){
			if(dt[axx][axy]=='.'){
				return 1;
			}
		}
	}
	return 0;
}
int upd(int xwz,int ywz){
	if(!tag[xwz][ywz]){
		tag[xwz][ywz]=1;
		return 1;
	}
	return 0;
}
int run(int x,int y,int d,int tm){
	int ans=0;
	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			tag[i][j]=0;
		}
	}
	ans+=upd(x,y);
	for(int i=0;i<tm;i++){
		int xp,yp=0;
		if(d==0){
			xp=x;
			yp=y+1;
		}
		if(d==1){
			xp=x+1;
			yp=y;
		}
		if(d==2){
			xp=x;
			yp=y-1;
		}
		if(d==3){
			xp=x-1;
			yp=y;
		}
		if(cwz(xp,yp)){
			x=xp;
			y=yp;
		}
		else{
			d=(d+1)%4;
		}
		ans+=upd(x,y);
	}
	cout << ans << endl;
}
int main(){
	int t;
	freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	cin >> t;
	for(int akioi=0;akioi<t;akioi++){
		int kp,xp,yp,dp;
		cin >> n >> m >> kp >> xp >> yp >> dp;
		//cout << n << ' ' << m << ' ' << kp << endl << xp << ' ' << yp << ' ' << dp;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> dt[i+1][j+1];
			}
		}
		
			run(xp,yp,dp,kp);
	}
	return 0;
} 
