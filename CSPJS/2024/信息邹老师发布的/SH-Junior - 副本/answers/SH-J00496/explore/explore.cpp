#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans;
char g[1005][1005];
bool vis[1005][1005];
int dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
	int x,y,f;
};
queue<node> q;
int scan(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
	}else{
		print(x/10);
		putchar(x%10+'0');
	}
}
void bfs(){
	int i=0;
	q.push({x,y,d});
	vis[x][y]=1,ans++;
	while(!q.empty()&&i<=k){
		node t=q.front();
		q.pop();
		if(vis[t.x][t.y]==0){
			ans++;
			vis[t.x][t.y]=1;
		}
		int nx=t.x+dxy[t.f][0],ny=t.y+dxy[t.f][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]=='.'){
			q.push({nx,ny,t.f});
		}else q.push({t.x,t.y,(t.f+1)%4});
		i++;
	}
	print(ans);puts("");
	while(!q.empty()) q.pop();
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	T=scan();
	while(T--){
		memset(vis,0,sizeof(vis));
		n=scan(),m=scan(),k=scan(),x=scan(),y=scan(),d=scan(),ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		bfs();
	}
	return 0;
}
