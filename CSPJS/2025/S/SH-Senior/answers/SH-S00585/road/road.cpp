#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
struct Edge{
	int u,v,w;
}e[N];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int n,m,k,fa[N];
int get(int a){
	if(a==fa[a]) return a;
	else fa[a]=get(fa[a]);
}
void merge(int x,int y){
	if(get(x)!=get(y)) fa[get(x)]=get(y);
	return;
}
void break_merge(int x,int y){
	fa[x]=x;
	fa[y]=y;
	return;
}
void kruskal(){
	int cnt=0,ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if(get(u)!=get(v)){
			ans+=w;
			merge(u,v);
			cnt++;
		}
		if(cnt==n-1){
			cout<<ans;
			break;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	kruskal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

