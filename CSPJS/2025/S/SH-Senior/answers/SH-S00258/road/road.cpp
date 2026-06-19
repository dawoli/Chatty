#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+15,MAXM=1e6+1e5;
int N,M,K;
//int head[MAXN],tmphead[MAXN];
int cnt=0,tmpcnt=0;
struct edge{
	int from,to,w;
}E[MAXM],tmpE[MAXM];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void add(int u,int v,int w){
	E[++cnt].from=u;
	E[cnt].to=v;
	E[cnt].w=w;
}
void tmpadd(int u,int v,int w){
	tmpE[++tmpcnt].from=u;
	tmpE[tmpcnt].to=v;
	tmpE[tmpcnt].w=w;
}

int fa[MAXN];
int find(int x){
	if(x==fa[x]) return x;
	return x=fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}

int c[10],a[10][MAXN];
bool cho[10];

long long kruskal(int tmpcnt,int tot){
	long long res=0;
	sort(tmpE+1,tmpE+1+tmpcnt,cmp);
//	cout << "!!!" << tmpcnt << ' ' << tot << endl;
//	for(int i=1;i<=tmpcnt;++i) cout << tmpE[i].from << ' ' << tmpE[i].to << ' ' << tmpE[i].w << endl; 
//	cout << "!!!" << endl;
	int ecnt=0;
	for(int i=1;i<=tmpcnt;++i){
		int u=tmpE[i].from,v=tmpE[i].to;
		if(find(u)==find(v)) continue;
		merge(u,v);
		res+=tmpE[i].w;
		ecnt++;
		if(ecnt==tot-1) break;
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> N >> M >> K;
	for(int i=1;i<=M;++i){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	bool flag=1;
	for(int i=0;i<K;++i){
		cin >> c[i];
		if(c[i]) flag=0;
		bool sm=0;
		for(int j=1;j<=N;++j){
			cin >> a[i][j];
			if(a[i][j]==0) sm=1;
		}
		flag=flag&sm;
	}
	long long ans=0x3fffffff;
	if(flag){
		for(int j=1;j<=N+13;++j) fa[j]=j;
		ans=0;
		for(int j=0;j<K;++j){
			ans+=c[j];
			for(int ii=1;ii<=N;++ii){
				add(N+j+1,ii,a[j][ii]);
			}
		}
		sort(E+1,E+1+cnt,cmp);
//		cout << "!!!" << cnt << ' ' << N+K << endl;
//		for(int i=1;i<=cnt;++i) cout << E[i].from << ' ' << E[i].to << ' ' << E[i].w << endl; 
//		cout << "!!!" << endl;
		int ecnt=0;
		for(int i=1;i<=cnt;++i){
			int u=E[i].from,v=E[i].to;
			if(find(u)==find(v)) continue;
			merge(u,v);
			ans+=E[i].w;
			ecnt++;
			if(ecnt==N+K-1) break;
		}
			
		cout << ans;
	}
	else{
	
	for(int i=0;i<(1<<K);++i){
		long long tmpans=0;
		for(int j=1;j<=cnt;++j) tmpE[j]=E[j];
		for(int j=1;j<=N+13;++j) fa[j]=j;
		tmpcnt=cnt;
		int tmp=i,tot=N;
		for(int j=0;j<K;++j){
			cho[j]=tmp&1;
			if(cho[j]){
				tot++;
				tmpans+=c[j];
				for(int ii=1;ii<=N;++ii){
					tmpadd(N+1+j,ii,a[j][ii]);
//					cout << "@@" << N+1+j << ' ' << ii << ' ' << a[j][ii] << endl;
				}
			}
			tmp>>=1;
		}
		tmpans+=kruskal(tmpcnt,tot);
		if(tmpans<=ans) ans=tmpans;
	}
	cout << ans;
	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
