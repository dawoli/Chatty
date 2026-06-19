#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
	
}e[1000009];
bool cmp(const edge&a,const edge&b){
	return a.w<b.w;
}
int id[10009];
int root(int x){
	if(x==id[x]) return x;
	else return id[x]=root(id[x]);
}
int n,m,k;
int ans=0;
void kru(){
	int cnt=n-1;
	for(int i=1;i<=m;i++){		
		if(root(e[i].u)!=root(e[i].v)){
			ans+=e[i].w;
			cnt--;
			int ru=root(e[i].u),rv=root(e[i].v);
			id[ru]=id[rv];
		}
		if(cnt==1) return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	if(k==0){
		kru();
		cout<<ans;
	}
	return 0;
} 
