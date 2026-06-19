#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;

int n,m,k;
int f[N],ranks[N];
long long c[N],a[20][N];

struct node{
	int u,v;
	long long w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
vector<node> l,g;

int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(ranks[fx]<ranks[fy]){
		f[fx]=fy;
	}
	else{
		f[fy]=fx;
		if(ranks[fx]==ranks[fy]){
			ranks[fx]++;
		}
	}
	return;
}
//并查集 



long long res=1e17;

void solve1(long long cnt){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	} 
	sort(g.begin(),g.end());
	for(int i=0;i<g.size();i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(find(u)!=find(v)){
			cnt+=w;
			merge(u,v);
		}
	}
	//m+n*k<1e6
	res=min(res,cnt);
}
int vis[20];

void dfs(int x){
	if(x>k){
		long long cnt=0;
		for(int i=1;i<=k;i++){
			if(!vis[i]) continue;//不选 
			cnt+=c[i];//改善乡镇花费 
			for(int j=1;j<=n;j++){
				g.push_back({n+i,j,a[i][j]});//建立和其他所有城市边 
			}
		}
		for(int i=0;i<m;i++){
			g.push_back(l[i]);
		}
		//k*n<1e5
		solve1(cnt);//计算最小花费 //m<1e6
		g.clear();
		
		return;
	}
	vis[x]=1;//选 
	dfs(x+1);
	vis[x]=0;//不选 
	dfs(x+1);
}
//选乡镇 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		l.push_back({u,v,w});
	}

	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		} 
	}
	if(k==0){
		long long cnt=0;
		sort(f.begin(),f.end());
		for(int i=0;i<g.size();i++){
			int u=g[i].u,v=g[i].v,w=g[i].w;
			if(find(u)!=find(v)){
				cnt+=w;
				merge(u,v);
			}	
		}
		cout << cnt << endl;
		return 0;	
	}
	dfs(1);	//pow(2,k)<1500
	cout << res << endl;  
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
