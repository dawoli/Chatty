#include <iostream>
#include <cstdio>
using namespace std;


int T,n,m,k;
char map[1000][1000];
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int cnt[1000][1000]={0};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	/*
	对于每一步存储当前方向，等增量
	dis={{0,1},{1,0},{0,-1},{-1,0}}
	每一次改变状态
	1 向前走
	2 向 右边 转
	每一次
	标记走的格子 
	判断k是否超出，接着执行下一步 或者 退出 
	*/
	
	cin>>T;
	for (int t=1;t<=T;t++){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>map[i][j];
				cnt[i][j]=0;
			}
		}
		cnt[x][y]=1;
		int nk=0;
		while (nk<k){
			int nx=x+dis[d][0];
			int ny=y+dis[d][1];
			if (nx>=1 && nx<=n && ny>=1 && ny<=m && map[nx][ny]=='.'){
				x=nx,y=ny;
				cnt[nx][ny]=1;
				nk++;
				if (nk>=k)break;
				
			}else{
				d=(d+1)%4;
				nk++;
				if (nk>=k)break;
			}
		}
		
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (cnt[i][j]==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
