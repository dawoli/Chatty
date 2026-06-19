// Time complex: O(2^k x n) (if u dont care about BinChaJi) 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 20005
#define M 1000005
#define K 15
#define fio(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define fclo() fclose(stdin);fclose(stdout);

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*w;
}

int n,k;
struct edge{
	int u,v,w;
}e[M];
vector<edge>chose;

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int c[K];
edge a[K][N];

int fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

ll ans=0x3f3f3f3f3f3f3f3f;

void dfs(int x,ll tot,vector<edge>&ee){
//	cout<<x<<' '<<tot<<endl;
//	for(edge& x:ee)cout<<x.u<<' '<<x.v<<' '<<x.w<<endl;
	
	ll now=0;
	for(edge& x:ee)now+=x.w;
	ans=min(ans,now+tot);//cout<<ans<<endl<<endl;
	for(int i=x+1;i<=k;i++){
		// merge
		vector<edge>ee2;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		
		int k1=0,k2=1;
		while(k1<ee.size()&&k2<=n){
			if(ee[k1].w<a[i][k2].w){
				if(find(ee[k1].u)!=find(ee[k1].v)){
					fa[find(ee[k1].u)]=find(ee[k1].v);
					ee2.push_back(ee[k1]);
				}
				k1++;
			}else{
				if(find(a[i][k2].u)!=find(a[i][k2].v)){
					fa[find(a[i][k2].u)]=find(a[i][k2].v);
					ee2.push_back(a[i][k2]);
				}
				k2++;
			}
		}
		while(k1<ee.size()){
			if(find(ee[k1].u)!=find(ee[k1].v)){
				fa[find(ee[k1].u)]=find(ee[k1].v);
				ee2.push_back(ee[k1]);
			}
			k1++;
		}
		while(k2<=n){
			if(find(a[i][k2].u)!=find(a[i][k2].v)){
				fa[find(a[i][k2].u)]=find(a[i][k2].v);
				ee2.push_back(a[i][k2]);
			}
			k2++;
		}
		dfs(i,tot+c[i],ee2);
	}
}

int main(){
	fio("road");
	int m;
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			chose.push_back(e[i]);
		}
	}
	
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j].u=n+i;
			a[i][j].v=j;
			a[i][j].w=read();
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	dfs(0,0,chose);
	cout<<ans<<endl;
	
	fclo();
	return 0;
}
