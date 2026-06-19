#include<iostream>
#include<set>
using namespace std;
struct node{
	int v,to;
	node *next,*prev;
	node(int u,int t){
		v = u;
		to = t;
		next = nullptr; 
		prev = nullptr;
	}
	void insert(int v,int to){
		if(next==nullptr){
			next = new node(v,to);
			next->prev=this;
			return;
		}
		next->insert(v,to);
		return;
	}
	node* del(){
		node* n = next;
		next = nullptr;
		return n;
	}
	~node(){
		if(next!=nullptr)
			delete next;
	}
};
int incounts[2000];
node* g[2000];
int n,m,k;
int ma = 0;
node* ed = nullptr;
node* dfs(int p,set<int>visited){
	node* edge = g[p];
	visited.insert(p);
	while(edge!=nullptr){
		bool flag = true;
		if(visited.count(edge->to)) return edge;
		node* ret = dfs(edge->to,visited);
		if(ret!=nullptr){
			if(edge->v>ma&&incounts[p]>1||edge->to==1){
				ma = edge->v;
				ed = edge;
			}
			if(ret->to==p){
				auto pos = g;
				for(;pos < g+n+k+1;pos++) if(*pos==ed) break;
				if(pos!=g+n+k+1)*pos = ed->del();
				else{
					ed->next->prev = ed->prev;
					ed->prev->next = ed->del();
				}
				ma = 0;
				ed = nullptr;
				flag = false;
			}
		}
		if(flag) edge=edge->next;
	}
	return nullptr;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		if(g[u]==nullptr){
			g[u]=new node(w,v);
		}else{
			g[u]->insert(w,v);
		}
		if(g[v]==nullptr){
			g[v]=new node(w,u);
		}else{
			g[v]->insert(w,u);
		}
		incounts[u]++;
		incounts[v]++;
	}
	for(int i = 1;i <= k;i++){
		int r;
		cin>>r;
		for(int j = 0;j < n;j++){
			int w;
			cin>>w;
			if(g[n+1]==nullptr){
				g[n+1]=new node(w,j);
			}else{
				g[n+1]->insert(w,j);
			}
			if(g[j]==nullptr){
				g[j]=new node(w+r,n+1);
			}else{
				g[j]->insert(w+r,n+1);
			}
			incounts[n+i]++;
			incounts[j]++;
		}
	}
	set<int> sssss;
	dfs(1,sssss);
	int ans = 0;
	for(int i = 1;i <= n+k;i++){
		auto p = g[i];
		while(p!=nullptr){
			ans+=p->v;
			p=p->next;
		}
	}
	cout<<ans<<endl;
	return 0;
}
