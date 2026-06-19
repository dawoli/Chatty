#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
const int MAXK=11;
long long n,m,k,sum=0,cj[MAXK];
int fa[MAXN+MAXK];//,cnt[MAXN+MAXK];
bool isCity[MAXN+MAXK];
int get(int x){
	if(fa[x]==x)
	    return fa[x];
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	if(x!=n+k+1)
	    fa[y]=get(fa[x]);
}
struct node{
    int u,v;
	long long w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
vector<node> Map;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		Map.push_back({u,v,w});
		Map.push_back({v,u,w});
		isCity[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>cj[i];
		Map.push_back({n+k+1,n+i,cj[i]});
		fa[n+i]=n+i;
		for(int j=1;j<=n;j++){
			long long c;
			cin>>c;
			Map.push_back({n+i,j,c});
			Map.push_back({j,n+i,c});
		}
	}
	sort(Map.begin(),Map.end());
	for(int i=0;i<Map.size();i++){
		int u=Map[i].u,v=Map[i].v;
		long long w=Map[i].w;
		if(get(u)==get(v)||(isCity[u]&&!isCity[v])||(isCity[v]&&!isCity[u]))
			continue;
		if(u==n+k+1){
			isCity[v]=1;
			//cnt[v]++;
			sum+=w;
			continue;
		}
		merge(u,v);
		//cnt[u]++;
		//cnt[v]++;
		sum+=w;
	}
	for(int i=1;i<=k;i++)
	    if(fa[n+i]==n+k+i||fa[n+i]==n+i)
	        sum-=cj[i];
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
