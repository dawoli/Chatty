#include<bits/stdc++.h>
using namespace std;
struct Node{
	int e,c;
};
//I'm dying!!!!
int n,m,k;
vector<Node> map1[10005];
int c1[15];
int x[15][10005];
bool city[15]={0};
int road[10005][10005]={0};
bool dir[10005][10005]={0};
int ciod[10005][10005]={0};
int out=0x3f3f3f3f;
void dijstr(int s){
	queue<int> q;
	int dis[10005];
	int ans;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<u<<"\n";
		for(int i=0;i<map1[u].size();i++){
			Node v=map1[u][i];
			int now=0;
			//u->v.e
			if(dir[u][v.e]){
				if(!road[u][v.e]){
					now+=v.c;
					//!!!
				}
			}
			else{
				if(city[ciod[u][v.e]]){
					if(!road[u][v.e]){
						now+=v.c;
						//!!!
					}
				}
				else{
					now+=c1[ciod[u][v.e]];
					//!!!
					now+=v.c;
					//!!!
				}
			}
			if(dis[u]+now<dis[v.e]){
				dis[v.e]=dis[u]+now;
				if(dir[u][v.e]){
					if(!road[u][v.e]){
						ans-=road[u][v.e];
						road[u][v.e]=v.c;
//						printf("This road is new %d\n",v.c);
					}
				}
				else{
					if(city[ciod[u][v.e]]){
						if(!road[u][v.e]){
							ans-=road[u][v.e];
							road[u][v.e]=v.c;
//							printf("The city is old,This road is new %d\n",v.c);
						}
					}
					else{
						city[ciod[u][v.e]]=1;
						road[u][v.e]=1;
//						printf("The city is new,This road is new %d\n",c1[ciod[u][v.e]]+v.c);
					}
				}
				q.push(v.e);
//				printf("you make a road between %d and %d ,it cost %d\n",u,v.e,now);
				ans+=now;
			}
		}
	}
//	cout<<ans<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
	out=min(out,ans);
}
int temp[10004][10005];
int main(){
	freopen("road.in","r",stdin);freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		Node a,b;
		a.e=v;a.c=c;
		b.e=u,b.c=c;
		map1[u].push_back(a);
		map1[v].push_back(b);
		dir[u][v]=1;
		dir[v][u]=1;
	}
	
	memset(temp,0x3f3f3f3f,sizeof(temp));
	for(int i=1;i<=k;i++){
		cin>>c1[i];
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
			for(int l=j-1;l>=1;l--){
				Node a,b;
				a.e=l;
				b.e=j;
				a.c=x[i][j]+x[i][l];
				b.c=x[i][j]+x[i][l];
				map1[j].push_back(a);
				map1[l].push_back(b);
				if(x[i][j]+x[i][l]+c1[i]<temp[j][l]){
					ciod[j][l]=i;ciod[l][j]=i;
					temp[j][l]=x[i][j]+x[i][l]+c1[i];
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++)dijstr(i);
	cout<<out;
}
