#include<bits/stdc++.h>
using namespace std;
struct edge{
	int l,v;
};
struct node{
	int l,v;
	friend bool operator<(node a,node b){
		return a.l<b.l;
	}
};
priority_queue<node>a;
vector<edge>to[10001];
bool vis[10001];
int xt[11][10001];
int main(){
	freopen("rode1.in","r",stdin);
	freopen("rode1.out","w",stdout);
	int n,m,k,t,s=1,f,e;
	long long r=0;
	edge u;
	node q;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t>>u.l>>u.v;
		to[t].push_back(u);
		
		to[t].push_back(u);
		swap(t,u.l);
	}
	for(int i=1;i<=k;i++){
		cin>>z[i][0];
		if(z[i][0]!=0)return 0;
		for(int j=1;j<=n;j++){
			cin>>z[i][j];
			if(z[i][j]==0){
				s=j;
			}
		}
	}
	vis[1]=1;
	for(int i=0;i<to[1].size();i++){
		q.l=to[1][i].l;
		q.v=to[1][i].v;
		a.push(q);
	}
	while(s<n){
		if(vis[f]){
			a.pop();
			continue;
		}
		r+=a.top().v;
		f=a.top().l;
		a.pop();
		vis[f]=1;	
		for(int i=1;i<=to[f].size();i++){
			q.l=to[f][i].l;
			if(vis[q.l])continue;
			q.v=to[f][i].v;
			a.push(q);
		}
		s++;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
