#include<bits/stdc++.h>
#define N 5000009
#define M 200009
#define ll long long
#define B 131ll
#define p 1145141919827ll
using namespace std;
bool beg;
int ch[N][30],dfn[N],ed[N],fa[N],tot,tt,n,m;
ll ans[M];
basic_string<int> g[N];
struct node{
	int o;ll x;int y,z;
	bool operator<(const node &b){
		return (x<b.x)||(x==b.x&&y<b.y)||(x==b.x&&y==b.y&&o<b.o);
	}
} Q[N+(M<<1)];
queue<int> q;
char s1[N],s2[N];
int pos[M];ll a[M];
bool eedd;
void dfs(int u){
	dfn[u]=++tt;
	for(int v:g[u])dfs(v);
	ed[u]=tt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	cerr<<"Mem:"<<(&beg-&eedd)/(1<<20)<<"\n";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(s1+1)>>(s2+1);int len=strlen(s1+1);
		int u=0;ll x=0;
		for(int j=1;j<=len;j++){
			if(!ch[u][s1[j]-'a'])ch[u][s1[j]-'a']=++tot;
			u=ch[u][s1[j]-'a'];
			x=(x*B+(s1[j]^s2[j]))%p;
		}
		pos[i]=u;a[i]=x;
	}
	for(int i=0;i<26;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		g[fa[u]]+=u;
		for(int i=0;i<26;i++){
			if(ch[u][i])fa[ch[u][i]]=ch[fa[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[fa[u]][i];
		}
	}
	dfs(0);tt=0;
	for(int i=1;i<=n;i++){
		Q[++tt]=node{1,a[i],dfn[pos[i]],1};
		Q[++tt]=node{1,a[i],ed[pos[i]]+1,-1};
	}
	for(int i=1;i<=m;i++){
		cin>>(s1+1)>>(s2+1);int len=strlen(s1+1);if(strlen(s2+1)!=len)continue;
		int lim=1;
		for(int j=len;j;--j){
			if(s1[j]!=s2[j]){lim=j;break;}
		}
		int u=0;ll x=0;
		for(int j=1;j<=len;j++){
			u=ch[u][s1[j]-'a'];
			x=(x*B+(s1[j]^s2[j]))%p;
			if(j>=lim)Q[++tt]=node{2,x,dfn[u],i};
		}
	}
	sort(Q+1,Q+tt+1);Q[tt+1].x=-1;
	for(int i=1;i<=tt;i++){
		int j=i,sum=0;while(Q[j+1].x==Q[i].x)++j;
		for(int k=i;k<=j;k++){
			if(Q[k].o==1){
				sum+=Q[k].z;
			}
			else{
				ans[Q[k].z]+=sum;
			}
		}i=j;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
