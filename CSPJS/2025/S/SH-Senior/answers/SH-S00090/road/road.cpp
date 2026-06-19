#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int n,m,k,e;
map<int,long long>isv;
struct node{
	int u,v;
	long long w;
}edge[2000006];
bool cmp(node a,node b){
	return a.w<b.w;
}

int fa[10030];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

long long mst=0;
long long solve1(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int tot=0;
	for(int i=1;i<=e;i++){
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v)continue;
		fa[u]=v;
		mst+=edge[i].w;
		if(++tot==n+k)break;
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	}
	return mst;
}

bool isopen[10030];
long long solve2(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int tot=0;
	for(int i=1;i<=e;i++){
		if(!isopen[edge[i].u]||!isopen[edge[i].v])continue;
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v)continue;
		fa[u]=v;
		mst+=edge[i].w;
		if(++tot==n+k)break;
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	}
	return mst;
}
long long res=0x3f7f7f7f7f7f7f7f;
void dfs(int cur,int pos,long long temp){
	if(cur==k+n){
		res=min(solve2()+temp,res);
		return ;
	}
	isopen[cur+1]=1;
	dfs(cur+1,1,temp+isv[cur+1]);
	isopen[cur+1]=0;
	dfs(cur+1,0,temp);
}
int main(){
	 freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	e=m+1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	bool ifA=1;
	for(int i=1+n;i<=k+n;i++){//Ïç´å±àºÅn+1~n+k 
		int c;
		cin>>c;
		if(c)ifA=0;
		isv[i]=c;//c=0 -> nonvillage   c!=0 -> isvillage
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			edge[e]={i,j,w};
			e++;
		}
	}
	e--;
	sort(edge+1,edge+1+e,cmp);
//	cout<<e<<endl;
//	for(int i=1;i<=e;i++){
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
//	}
//	cout<<"----\n";
	if(k==0||ifA){//mst
		cout<<solve1();
	}
	else{
		for(int i=1;i<=n;i++){
			isopen[i]=1;
		}
		isopen[n+1]=1;
		dfs(n+1,1,isv[n+1]);
		isopen[n+1]=0;
		dfs(n+1,0,0);
		cout<<res;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
