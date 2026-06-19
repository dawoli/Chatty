#include <bits/stdc++.h>
using namespace std;
int mp[1100][1100];//0表示越界,1表示可通行,2表示障碍 
int flag[1100][1100];
int n,m,k,sx,sy,sd;//d=0代表东,d=1代表南,d=2代表西,d=3代表北
bool check(int x,int y){
	if(mp[x][y]==0||mp[x][y]==2)return false;
	else return true;
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void Epr(int x,int y,int d,int step){
	flag[x][y]=1;
	if(step==0)return;
	int nx=x+dx[d],ny=y+dy[d];
	if(check(nx,ny)==false){
		Epr(x,y,(d+1)%4,step-1);
	}else{
		Epr(nx,ny,d,step-1);
	}
	return;
}
int Comp(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(flag[i][j]==1)ans++;
		}
	}
	return ans;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		memset(flag,0,sizeof(flag));
		cin>>n>>m>>k>>sx>>sy>>sd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char a;
				cin>>a;
				if(a=='x'){
					mp[i][j]=2;
				}else mp[i][j]=1;
			}
		}
		Epr(sx,sy,sd,k);
		cout<<Comp()<<endl;
	}
	return 0;
}
