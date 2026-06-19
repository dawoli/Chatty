#include<bits/stdc++.h>
using namespace std;
#define N 1001
typedef long long LL;
LL n,m,k,ans=0;
LL x,y,d;
LL tx,ty;
int mp[N][N];	//0为空地，1为障碍 
bool vst[N][N];	//统计走过的位置 
bool check(LL xx,LL yy){	//判断是否合法位置 
	if(xx<1||xx>n) return false;
	if(yy<1||yy>m) return false;
	if(mp[xx][yy]==1) return false;
	return true;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T; cin>>T;
	char opt;
	while(T--){
		ans=0;
		memset(mp,0,sizeof(mp));
		memset(vst,0,sizeof(vst));
		cin>>n>>m>>k;	//地图的行、列，运行步数 
		cin>>x>>y>>d;	//位置、方向 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>opt;
				mp[i][j]=(opt=='.'? 0 : 1);
			}
		} 
		vst[x][y]=1;
		while(k--){	//运行k步
			if(d==0){		//向右 
				tx=x,ty=y+1;
			}else if(d==1){	//向下 
				tx=x+1,ty=y;
			}else if(d==2){	//向左 
				tx=x,ty=y-1; 
			}else if(d==3){	//向上 
				tx=x-1,ty=y;
			}
			if(check(tx,ty)){	//如果能到达tx,ty 
				x=tx,y=ty;
				vst[x][y]=1;
				//printf("走到(%d,%d)，方向%d\n",x,y,d);
			}else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vst[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

1
3 3 2
2 2 0
.x.
..x
.x.
*/
