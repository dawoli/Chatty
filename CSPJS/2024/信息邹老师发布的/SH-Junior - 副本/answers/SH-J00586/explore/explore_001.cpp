#include<bits/stdc++.h>
using namespace std;

int xydx(int x,int y,int fx){
	int x1,y1;
	if(fx==0)return x;
	if(fx==1)return x+1;
	if(fx==2)return x;
	if(fx==3)return x-1;
}

int xydy(int x,int y,int fx){
	int x1,y1;
	if(fx==0)return y+1;
	if(fx==1)return y;
	if(fx==2)return y-1;
	if(fx==3)return y;
}
bool zgmap[1005][1005];
int jg(int n,int m,int k){
	int x,y,d,cnt=0;
	char map[1005][1005];
	cin>>x>>y>>d;
	zgmap[x][y]=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		int x1=xydx(x,y,d);
		int y1=xydy(x,y,d);
		if(x1>n || y1>m || x1<1 || y1<1 || map[x1][y1]=='x'){
			d=(d+1)%4;
		}else{
			x=x1;
			y=y1;
			zgmap[x][y]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zgmap[i][j]==true){
				cnt++;
				zgmap[i][j]=false;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k;
	int ans;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		ans=jg(n,m,k);
		cout<<ans<<endl;
	}
	return 0;
}
