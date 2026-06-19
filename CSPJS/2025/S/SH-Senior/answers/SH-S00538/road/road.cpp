#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline bool isdigit(char x){
	return '0'<=x && x<='9';
}

int qread(){
	int ans=0;
	char c;
	while(!isdigit(c=getchar()));
	ans=c-'0';
	while(isdigit(c=getchar())){
		ans*=10;
		ans+=c-'0';
	}
	return ans;
}

// k<=10 
// N包含新建城市 
const int N=1e4+50;

struct Edge{
	// w: 修复费用 
	int u,v,w;
} edges[1000001];
bool operator<(Edge a, Edge b){
	return a.w>b.w;
}

int n,m,k;

// 并查集 
// sz不记录新建城市 
// 如果新建城市只连了一条边，那么它是不必要的 
int fa[N],sz[N],deg[N];
ll ans,cs_ans[11];
ll c[11]; 
int getroot(int x){
	return fa[x]==x?x:fa[x]=getroot(fa[x]);
}

int merge(int u,int v){
	int ur=getroot(u);
	int vr=getroot(v);
	if(ur==vr) return sz[ur];
	deg[u]++;
	deg[v]++;
	if(sz[ur]<sz[vr]) swap(ur,vr);
	fa[vr]=ur;
	sz[ur]+=sz[vr];
	return sz[ur];
}

// 0为原有，后面为新建 
priority_queue<Edge> q[11];

int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	n=qread();
	m=qread();
	k=qread();
	
	for(int i=0;i<m;i++){
		q[0].push({qread(),qread(),qread()});
	}
	
	iota(fa,fa+1+n+k,0);
	fill(sz,sz+1+n,1);
	
	for(int i=1;i<=k;i++){
		c[i]=qread();
		for(int j=1;j<=n;j++){
			q[i].push({i+n,j,qread()});
		}
	}
	
	while(true){
		// 择优
		Edge best={-1,-1,-1};
		int cj=-1;
		int bestxx=INT_MAX;
		for(int i=0;i<=k;i++){
			while(!q[i].empty()){
				Edge now = q[i].top();
				if(getroot(now.u)==getroot(now.v)) {
					q[i].pop();
					continue;
				}
				if((c[i]+now.w)<bestxx){
					best=now;
					bestxx=c[i]+now.w;
					cj=i;
				}
				break;
			}
		}
		// 最优边 
		q[cj].pop();
		// 贡献
		ans+=bestxx;
		cs_ans[cj]+=bestxx;
		c[cj]=0;
		// 合并
		if(merge(best.u,best.v)>=n){
			// 联通 
			break;
		}
	}
	
	for(int i=1;i<=k;i++){
		if(deg[i+n]==1){
			ans-=cs_ans[i+n];
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
