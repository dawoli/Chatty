#include<bits/stdc++.h>
using namespace std;
const int A=1000005,N=1005;
int p[A];
struct node{
	int l,r,num;
}a[N];
int head[N],cnt1=1;
struct edge{
	int v,nxt;
}e[N<<1+N];
void add(int u,int v){
	e[++cnt1].v=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
bool vis[N],coo[N];
int dfs(int p,int cos){
	int ans=0;
	vis[p]=1;
	queue<int> q;
	for(int i=head[p];i;i=e[i].nxt){
		int v=e[i].v;
		
		if(vis[v])continue;
		q.push(v);
	}
	if(!q.empty()){
		int 
	}
	vis[p]=0;
	return ans+a[p].num;
}
void clear(){
	
	
}
void solve(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(p[x]!=0){a[++cnt].num=x;a[cnt].l=p[x],a[cnt].r=i;}
		p[x]=i;
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(a[j].r<a[i].r)swap(a[i],a[j]);
			if(a[i].r-1>a[j].l){
				add(i,j);
				add(j,i);
			//	cout<<j<<" "<<i<<endl;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		add(0,i);
	}
	cout<<dfs(0,0);
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		clear();
		solve();
	}
}
