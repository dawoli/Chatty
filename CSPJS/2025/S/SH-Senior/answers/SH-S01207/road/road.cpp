#include<bits/stdc++.h>
using namespace std;
long long n,m,k,head[10009],cnt,a,b,c,kk[19][10009],fa[10009],bs,ans,jl[1009][1009];
struct murasame{
	int t;
	int f;
	long long v;
	bool operator < (const murasame &a) const{
		return a.v>v;
	}
}bian[3000009];
//void jb(int x,int y,int z){
//	bian[++cnt].t=y;
//	bian[cnt].nxt=head[x];
//	head[x]=cnt;
//	bian[cnt].v=z;
//}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void add(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=fa[yy];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int lmax=(1<<k);
	for(int i=1;i<=m;++i){
		cin>>a>>b>>c;
		bian[++cnt].f=a;
		bian[cnt].t=b;
		bian[cnt].v=c;
	}
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int j=1;j<=n;++j){
			cin>>kk[i][j];
		}
	}
	if(k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				jl[i][j]=1000000000000000;
				for(int kkk=1;kkk<=k;++kkk){
					jl[i][j]=min(kk[kkk][i]+kk[kkk][j],jl[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
		for(int j=i+1;j<=n;++j){
			bian[++cnt].f=i;
			bian[cnt].t=j;
			bian[cnt].v=jl[i][j];
		}
	}
	sort(bian+1,bian+1+cnt);
	for(int i=1;i<=cnt;++i){
		int x=bian[i].f;
		int y=bian[i].t;
		int vv=bian[i].v;
		if(find(x)!=find(y)){
			add(x,y);
			ans+=vv;
			++bs;
		}
		if(bs==n-1)break;
	}
	cout<<ans;
	return 0;
}
