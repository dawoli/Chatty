#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,ty=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ty=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*ty;
}
struct side{
	long long u,v,w;
};
vector<side> s;
int fa[10009];
long long c[20][10009],a[20],n,m,k,mn[11];
long long ans=LLONG_MAX/10;
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	fa[find(x)]=find(y);
	return;
}
bool cmp(const side&a,const side&b){
	if(a.w<b.w)
		return 1;
	return 0;
}
void kruskal(vector<side> e,int mx,long long sumk){
	mx+=n;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	long long sum=sumk,cnt=0;
	for(int i=0;i<e.size();i++){
		if(find(e[i].u)!=find(e[i].v)){
			join(e[i].u,e[i].v);
			sum+=e[i].w;
			cnt++;
			if(cnt==mx-1)
				break;
		}
	}
	ans=min(ans,sum);
}
void dfs(int i,vector<side> e,int cntk,long long sumk){
	if(sumk+mn[cntk]>=ans)
		return;
	if(i==k+1){
		kruskal(e,cntk,sumk);
		return;
	}
	dfs(i+1,e,cntk,sumk);
	for(int j=1;j<=n;j++)
		e.push_back({i+n,j,c[i][j]});
	dfs(i+1,e,cntk+1,sumk+a[i]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	long long u,v,w;
	for(int i=1;i<=m;++i){
		u=read(),v=read(),w=read();
		s.push_back({u,v,w});
	}
	sort(s.begin(),s.end(),cmp);
	vector<side> e=s;
	for(int i=1;i<=k;++i){
		a[i]=read();
		for(int j=1;j<=n;++j){
			c[i][j]=read();
			e.push_back({i+n,j,c[i][j]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<n-1;i++)
		mn[0]+=e[i].w;
	for(int i=n;i<n+k;i++)
		mn[i-n+1]=mn[i-n]+e[i].w;
	dfs(1,s,0,(long long)0);
	cout<<ans;
	return 0;
}
//赞美伟大的kruskal大人
//会不会卡常就看运气了 
//rp++ 
