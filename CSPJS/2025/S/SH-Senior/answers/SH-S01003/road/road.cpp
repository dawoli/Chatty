#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+1e5+5;
int n,m,k;
struct edge{
	int u,v,w;
}a[M],e[M];
int num;
int fa[N+10];
int v[15];
int c[15][N];
int ans=INT_MAX,res;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge i,edge j){
	return i.w<j.w;
}
void kruskal(){
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x==y) continue;
		fa[x]=y;
		res+=a[i].w;
	}
}
string turn2(int x){
	string s="";
	while(x){
		char p=x%2+'0';
		s+=p;
		x/=2;
	}
	reverse(s.begin(),s.end());
	while(s.size()<k) s='0'+s;
	return s;
}
void init(){
//	memset(a,0,sizeof a);
	for(int i=1;i<=m;i++){
		a[i]=e[i];
	}
	for(int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	num=m;
	res=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		e[i]=a[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&v[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	if(k==0){
		init();
		kruskal();
		printf("%d\n",res);
		return 0;
	}
	for(int i=0;i<pow(2,k);i++){
		init();
		string s=turn2(i);
		for(int j=0;j<k;j++){
			if(s[j]=='1'){
				for(int u=1;u<=n;u++){
					a[++num]={n+j+1,u,c[j+1][u]};
				}
				res+=v[j+1];
			}
		}
		kruskal();
		ans=min(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
