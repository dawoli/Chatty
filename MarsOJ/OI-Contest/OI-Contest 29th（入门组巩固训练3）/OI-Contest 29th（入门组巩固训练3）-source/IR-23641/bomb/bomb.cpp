#include<bits/stdc++.h>
#define int long long 
using namespace std;
const signed dx[4]={0,1,0,-1};
const signed dy[4]={1,0,-1,0};
int t;
struct node{
	int x,y,a,b;
};
node bfs(){
	
}
signed main(){
	//freopen("bomb.in","r",stdin);
	//freopen("bomb.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		int n,m;
		scanf("%lld%lld",&n,&m);
		string mp[1010];
		bool vis[1010][1010];
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}
		int mina=INT_MAX,minb=INT_MAX;
		queue<node>q;
		q.push({1,1,0,0});
		while(!q.empty()){
			node p=q.front();
			if(p.x==n&&p.y==m){
				if(p.b<minb){
					minb=p.b;
					mina=p.a;
				}
				else if(p.b==minb){
					mina=min(mina,p.a);
				}
				q.pop();
				continue;
			}
			for(int i=0;i<4;i++){
				if(p.x+dx[i]>=1&&p.x+dx[i]<=n&&p.y+dy[i]>=1&&p.y+dy[i]<=m&&mp[p.x+dx[i]][p.y+dy[i]]!='*'&&vis[p.x+dx[i]][p.y+dy[i]]==0){
					int x=p.x+dx[i],y=p.y+dy[i];
					if(mp[x][y]=='.'){
						q.push({x,y,p.a+1,p.b});
						vis[x][y]=1;
					}
					else if(mp[x][y]=='$'&&p.b+1<=minb){
						q.push({x,y,p.a+1,p.b+1});
						vis[x][y]=1;
					}
					else{
						continue;
					}
				}
			}
			q.pop();
		}
		printf("%d %d\n",minb,mina);
	}
	return 0;
}
