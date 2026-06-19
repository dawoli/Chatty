#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=10005;
const int MAXK=15;
const int INF=0x3f3f3f;
struct Node{
	long long to,key;
};
vector<Node> e[MAXN];
long long dis[MAXN];
int c[MAXK][MAXN];
int v_village[MAXK];
int w_village[MAXN];
int w_village_from[MAXN];
bool w_village_i[MAXN];
bool city_vis[MAXN];
bool village_vis[MAXK];
bool if_v[MAXK][MAXN];
int n,m,k;
long long op1,op2,op3;
long long sum;
void prim(int u,int step){
	city_vis[u]=1;
	step++;
	if(step==n)return ;
	for(auto v:e[u]){
		if(city_vis[v.to])continue ;
		if(dis[v.to]>v.key){
			dis[v.to]=v.key;
			w_village[v.to]=0;
			//w_village_from[v.to]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(city_vis[i])continue ;
		for(int j=1;j<=k;j++){
			long long cnt=0;
			if(!village_vis[j])cnt+=v_village[j];
			if(!if_v[j][u])cnt+=c[j][u];
			if(!if_v[j][i])cnt+=c[j][i];
			if(dis[i]>=cnt){
				w_village[i]=j;
				//w_village_from[i]=u;
				//w_village_i[i]=village_vis[j];
				dis[i]=cnt;
			}
		}
	}
	long long mindis=INF;
	int mindis_i=0;
	for(int i=1;i<=n;i++){
		if(city_vis[i])continue ;
		if(dis[i]<mindis){
			mindis=dis[i];
			mindis_i=i;
		}
	}
	if(w_village[mindis_i]>0){
		if(village_vis[w_village[mindis_i]]==0){
			village_vis[w_village[mindis_i]]=1;
			/*
			for(int i=1;i<=n;i++){
				if(city_vis[i])continue ;
				if(w_village_i[i]==0&&w_village[i]==w_village[mindis_i]){
					w_village_i[i]=1;
					dis[i]-=v_village[i];
				}
			}
			*/
		}
		if_v[w_village[mindis_i]][mindis_i]=1;
		if_v[w_village[mindis_i]][/*w_village_from[mindis_i]*/u]=1;
	}
	sum+=mindis;
	prim(mindis_i,step);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,INF,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&op1,&op2,&op3);
		e[op1].push_back({op2,op3});
		e[op2].push_back({op1,op3});
	}
	for(int i=1;i<=k;i++){
		cin>>v_village[i];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	prim(1,0);
	cout<<sum<<endl;
	return 0;
}
