#include <set>
#include <vector>
#include <cstring>
#include <iostream>

const int Max = 4000022;
struct edge{
	int v, id;
	bool operator<(edge e) const{
		return this->v < e.v;
	}
};
std::set<edge> mp[Max];
int epts[Max];
int id,qid;

std::vector<int> queries[Max];
int queLst[Max], qneed[Max], ans[Max];

void addEdge(int u, int v, int avoid);

int vis[Max];
void dfs(int u, int ep, int lun, int last);

int k;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int ttt;std::cin >> ttt;
for(int iii = 0;iii<ttt;iii++)
{
	id = qid = 0;
	memset(mp, 0, sizeof(mp))    ;
	memset(epts, 0, sizeof(epts));
	memset(queries, 0, sizeof(queries));
	memset(queLst, 0, sizeof(queLst));
	memset(qneed, 0, sizeof(qneed));
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	
	int n, q;std::cin >> n >> k >> q;
	for(int i = 1;i<=n;i++){
		int l;std::cin >> l;
		int lst;std::cin >> lst;
		for(int j = 2;j<=n;j++){
			int now;std::cin >> now;
			addEdge(lst, now, i);
		}
	}
	
	for(int i = 1;i<=q;i++){
		int r, c;std::cin >> r >> c;
		queries[c].push_back(i);
		qneed[i]  = r;
	}
	
	dfs(1, 0, lun, 0);
	
	for(int i = 1;i<=n;i++)
		std::cout << ans[i] << std::endl;
} 
}

void addEdge(int u, int v, int avoid){
	auto k = mp[u].find({v, avoid});
	if(k == mp[u].end()){
		mp[u].insert({v, ++id});
		epts[id] = avoid;
	}
	else
		epts[k->id] = 0;
}

void dfs(int u, int ept, int lun, last)
{
	if(vis[u]==-1)	return;
	else if(vis[u]!=0)	vis[u]=-1;
	else	vis[u] = ept;
	
	for(int e:mp[u]){
		if()
	}
}
