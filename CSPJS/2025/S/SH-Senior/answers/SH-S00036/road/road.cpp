//¿œ“Ø48pt∂ºtm≤ªπª 
#include<bits/stdc++.h>
using namespace std;
struct rd{
	int l, v;
};
struct mn{
	int l, v;
	bool operator<(const mn a) const{
		return l<a.l;
	}
};
priority_queue <mn> a;
vector <rd> to[10001];
bool vis[10001];
int xt[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k, t, s=1, ql, bn;
	long long r=0;
	rd u;
	mn q;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &t, &u.l, &u.v);
		to[t].push_back(u);
		swap(t,u.l);
		to[t].push_back(u);
	}
	for(int i=1;i<=k;i++){
		scanf("%d", &xt[i][0]);
		if(xt[i][0]!=0) return 0;
		for(int j=1;j<=n;j++){
			scanf("%d", &xt[i][j]);
			if(xt[i][j]==0){
				bn=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(j==bn) continue;
			t=bn, u.l=j, u.v=xt[i][j];
			to[t].push_back(u);
			swap(t,u.l);
			to[t].push_back(u);
		}
	}
	vis[1]=1;
	for(int i=0;i<to[1].size();i++){
		q.l=to[1][i].l;
		q.v=to[1][i].v;
		a.push(q);
	}
	while(s<n){
		ql=a.top().l;
		if(vis[ql]){
			a.pop();
			continue;
		}
		r+=a.top().v;
		vis[ql]=1;
		printf("%d\n", ql);
		a.pop();
		for(int i=0;i<to[ql].size();i++){
			q.l=to[ql][i].l;
			if(vis[q.l]) continue;
			q.v=to[ql][i].v;
			a.push(q);
		}
		s++;
	}
	printf("%lld", r);
	return 0;
}
