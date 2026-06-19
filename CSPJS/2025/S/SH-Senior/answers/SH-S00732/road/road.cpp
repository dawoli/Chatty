#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+15;
void read(int&x){
	x=0;
	char c=getchar();
	while(c>57||c<48)c=getchar();
	while(c>47&&c<58){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return;
}
int n,m,k,extra[N];
struct node{
	int u,v,w;
}e;
vector<node>edges;
struct temp{
	int a[N];
}p;
vector<temp>v;
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int mx){
	set<int>st;
	set<int>ex;
	for(int i=1;i<=n;i++)st.insert(i);
	for(int i=n+1;i<=n+k;i++)ex.insert(i);
	for(int i=1;i<=mx;i++)fa[i]=i;
	int ans=0;
	sort(edges.begin(),edges.end(),cmp);
	for(auto i:edges){
		st.erase(i.u);
		st.erase(i.v);
		if(i.u>n){
			if(ex.find(i.u)!=ex.end()){
				ans+=extra[i.u];
				ex.erase(i.u);
			}
		}
		if(i.v>n){
			if(ex.find(i.v)!=ex.end()){
				ans+=extra[i.v];
				ex.erase(i.v);
			}
		}
		int u=find(i.u),v=find(i.v);
		if(u!=v){
			fa[v]=u;
			ans+=i.w;
		}
		if(!st.size())return ans;
	}
}
bool compare(temp a,temp b){
	return a.a[0]<b.a[0];
}
void solve(){
	read(n);read(m);read(k);
	for(int i=0;i<m;i++){
		read(e.u);read(e.v);read(e.w);
		edges.push_back(e);
	}
	if(!k){
		cout<<kruskal(n);
		return;
	}
	int ans=kruskal(n);
	bool spa=1;
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++)read(p.a[j]);
		v.push_back(p);
		extra[n+i+1]=p.a[0];
		spa&=p.a[0]==0;
	}
	if(spa){
		for(int i=0;i<k;i++)for(int j=1;j<=n;j++)edges.push_back({n+1+i,j,v[i].a[j]});
		cout<<kruskal(n+k);
		return;
	}
	sort(v.begin(),v.end(),compare);
	int sum=0;
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			node t={n+1+i,j,v[i].a[j]};
			edges.push_back(t);
		}
		sum+=v[i].a[0];
		ans=min(ans,kruskal(n+i+1));
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
4 2 5
4 3 4
2 3 7

4 4 1
1 4 6
4 2 5
4 3 4
2 3 7
0 1 8 2 4

4 4 1
1 4 6
4 2 5
4 3 4
2 3 7
1 1 8 2 4

4 4 2
1 4 6
4 2 5
4 3 4
2 3 7
1 1 8 2 4
100 1 3 2 4
*/
