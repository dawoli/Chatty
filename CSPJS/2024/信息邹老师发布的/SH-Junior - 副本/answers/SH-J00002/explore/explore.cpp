#include <bits/stdc++.h>
using namespace std;
//π¿º∆60 
int T,n,m,k,X,Y,D,ans,Q;
bool a[1005][1005];
bool pl[1005][1005];
int allans[10];
int p(int x,int y,int d,int k){
	if(k == 0) return ans;
	int XX=x,YY=y;
	if(d == 0){
		YY ++;
	}else if(d == 1){
		XX ++;
	}else if(d == 2){
		YY --;
	}else if(d == 3){
		XX --;
	}
	if(1 <= XX && XX <= n && 1 <= YY && YY <= m && a[XX][YY]==0){
		ans ++;
		if(pl[XX][YY] == 1) ans --;
		pl[XX][YY] = 1;
		p(XX,YY,d,k-1);
	}else{
		p(x,y,(d+1)%4,k-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>X>>Y>>D;
		pl[X][Y] = 1;
		ans ++;
		for(int j=1;j<=n;j++){
			for(int q=1;q<=m;q++){
				char r;
				cin>>r;
				if(r == '.') a[j][q] = 0;
				if(r == 'x') a[j][q] = 1;
			}
		}
		allans[Q] = p(X,Y,D,k);
		Q ++;
		//≥ı ºªØ£ø
		memset(pl,0,sizeof(pl));
		ans = 0;
	}
	//Q = 0 - T-1
	for(int i=0;i<T;i++){
		cout<<allans[i]<<endl;
	}
	return 0;
}
