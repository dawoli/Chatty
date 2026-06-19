#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v,w;
};
struct P{
	int u,v,w,c_num;
	bool operator >(const P& xxx) const{
		return w>xxx.w;
	}
};
vector<Edge> a[10010];
int n,m,k,c[20][10010],ans,choice,minn,c_pay[20],minx;
bool vis[10010],changed[20];
priority_queue<P,vector<P>,greater<P>> pq;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u].push_back((Edge){v,w});
		a[v].push_back((Edge){u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c_pay[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	vis[1]=true;
	choice=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<a[choice].size();j++){
			if(vis[a[choice][j].v]) continue;
			pq.push((P){choice,a[choice][j].v,a[choice][j].w,0});
//			printf("push:%d %d %d %d\n",choice,a[choice][j].v,a[choice][j].w,0);
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==true) continue;
			minn=2e9,minx=0;
			for(int xx=1;xx<=k;xx++){
				if(minn>(!changed[xx])*c_pay[xx]+c[xx][choice]+c[xx][j]){
					minn=(!changed[xx])*c_pay[xx]+c[xx][choice]+c[xx][j];
					minx=xx;
				}
			}
			pq.push((P){choice,j,minn,minx}); 
//			printf("push:%d %d %d %d\n",choice,j,minn,minx);
		}
		P p=pq.top();pq.pop();
//		while(!pq.empty()&&vis[p.v]){//pop valueless edges
//			pq.top();pq.pop();
//		}
//		cout<<"choice:"<<p.u<<" "<<p.v<<" "<<p.w<<" "<<p.c_num<<endl; 
		ans+=p.w;
		choice=p.v;
		changed[p.c_num]=true;
		vis[choice]=true;
	}
	cout<<ans;
	return 0;
}
