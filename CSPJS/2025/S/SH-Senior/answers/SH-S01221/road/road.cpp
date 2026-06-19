#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot;
typedef pair<int,int> PII; 
struct stu {
	int u,v,w;
} a[1000010];
int f[10010];
int t_c[15][10010];
vector<PII> G[10010];//{结点,权值}
int flag1[15],flag2[15],c[15];//flag1:权值，flag2:多少个点 
bool cmp(stu c,stu d) {
	return c.w<d.w;
}
void add(int x,int y,int z) {
	G[x].push_back({y,z});
}
int father(int x) {
	if(f[x]!=x) return f[x]=father(f[x]);
	return x;
}
void unionn(int x,int y) {
	int fx=father(x);
	int fy=father(y);
	if(fx!=fy) f[fx]=fy;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//kruskal
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>t_c[i][j];//bianhao;quanzhi
		}
	}
	sort(a+1,a+1+m,cmp);
	int k1=0;
	for(int i=1; i<=m; i++) {
		if(father(a[i].u)!=father(a[i].v)) {
			unionn(a[i].u,a[i].v);
			add(a[i].u,a[i].v,a[i].w);
			add(a[i].v,a[i].u,a[i].w);
			tot+=a[i].w;
			k1++;
			if(k1==n-1) break;
		}
	}
	if(k==0){
		cout<<tot;
		return 0;
	}
	int tot2=tot;
	//维护乡镇
	for(int i=1; i<=n; i++) {
		for(auto u:G[i]) {
			for(int j=1; j<=k; j++) {
				if(t_c[j][u.first]+t_c[j][i]+c[j]<=u.second) {
					tot=tot-u.second+t_c[j][u.first]+t_c[j][i]+c[j];
					c[j]=0;
				}
			}
		}
	}
	if(tot<=0) cout<<tot2;
	else cout<<tot;
	return 0;
}
