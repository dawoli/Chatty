#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair

const int MN=20005;
const int MM=2000005;
const int MK=15;
const int MAXN=0x7f7f7f7f7f7f7f;

int n,m,k,ans=MAXN;
int fa[MN];
int c[MK],a[MK][MN];

void init() {
	for(int i=1;i<=n+k;++i) {
		fa[i]=i;
	}
}
int get_fa(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=get_fa(fa[x]);
}
void merge(int x,int y) {
	x=get_fa(x);
	y=get_fa(y);
	fa[x]=y;
	return;
}

struct Edge{
	int u,v,w;
} e[MM]; 

struct EEdge{
	int u,v,w;
} ee[MM]; 

void cpye(int mmm) {
	for(int i=1;i<=mmm;++i) {
		e[i].u=ee[i].u;
		e[i].v=ee[i].v;
		e[i].w=ee[i].w;
	}
}

vector< pair<int,int> > g[MN];
//to, len 

bool cmp(const Edge &a,const Edge &b) {
	return a.w<b.w;
}

int krus(int nn,int mm) {
	init();
	sort(e+1,e+mm+1,cmp);
	int sum=0;	
	int edcnt=0;
	for(int i=1;i<=mm;++i) {
		int uu=e[i].u,vv=e[i].v,ww=e[i].w;
		uu=get_fa(uu);
		vv=get_fa(vv);
		if(uu!=vv) {
			fa[uu]=vv;
			g[uu].push_back(mp(vv,ww));
			g[vv].push_back(mp(uu,ww));
//			cout<<uu<<" "<<vv<<" "<<ww<<endl;
			sum+=ww;
			edcnt++;
			if(edcnt==(nn-1)) return sum;
		} 
	}
	return sum;
}

int dfsx[MK];
int mm,nowx,sumf;
void dfs(int now,int mmm,int sumff,int nowxx) {
	
//		for(int i=1;i<=now-1;++i) {
//			cout<<dfsx[i]<<" ";
//		}
//		cout<<endl;
//		cout<<mmm<<" "<<sumff<<" "<<nowxx<<endl;
//		cout<<endl;
	if(now>k) {
//		cout<<"*****"<<endl;
//		for(int i=1;i<=k;++i) {
//			cout<<dfsx[i]<<" ";
//		}
//		cout<<endl;
//		cout<<mmm<<" "<<sumff<<" "<<nowxx<<endl;
//		cout<<endl<<endl;
//		mm=m; sumf=0; nowx=n;
//		for(int i=1;i<=k;++i) {
//			if(dfsx[i]==1) {
//				++nowx;
//				sumf+=c[i];
//				for(int j=1;j<=n;++j) {
//					++mm;
//					ee[mm].u=nowx;
//					ee[mm].v=j;
//					ee[mm].w=a[i][j];
//				}
//			}
//		}
		cpye(mmm);
		sumff+=krus(nowxx,mmm);	
//		cout<<"***"<<sumff<<endl;
		ans=min(ans,sumff);
		return;
	} else {
		dfsx[now]=0;
		dfs(now+1,mmm,sumff,nowxx);
		dfsx[now]=1;
		mm=mmm; nowx=nowxx; sumf=sumff;
		++nowx;
		sumf+=c[now];
		for(int j=1;j<=n;++j) {
			++mm;
			ee[mm].u=nowx;
			ee[mm].v=j;
			ee[mm].w=a[now][j];
		}
		dfs(now+1,mm,sumf,nowx);
	}
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	 
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i) {
		scanf("%lld%lld%lld",&ee[i].u,&ee[i].v,&ee[i].w);	
	}
	for(int i=1;i<=k;++i) {
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j) {
			scanf("%lld",&a[i][j]);
		}
	}
	
//	cout<<a[1][926]<<endl;
	dfs(1,m,0,n);
	
	printf("%lld\n",ans);
	return 0;
} 
