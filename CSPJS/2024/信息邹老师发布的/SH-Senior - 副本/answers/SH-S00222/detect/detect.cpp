#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+10; int p[N]; bool vis[N],is[N]; int cnt[N];
struct Car { int d,v,a; }a[N];
struct Detect { vector<int>v; int cnt; }d[N];
void solve() {
  int n,m,l,v; scanf("%d %d %d %d",&n,&m,&l,&v);
  for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].d,&a[i].v,&a[i].a);
  for(int i=1;i<=m;i++) scanf("%d",&p[i]);
  int cnt=0;
  for(int i=1;i<=n;i++) {
  	for(int j=1;j<=m;j++)
	  if(p[j]>=a[i].d&&1ll*a[i].v*a[i].v+2ll*a[i].a*(p[j]-a[i].d)>1ll*v*v)
	    is[i]=true,d[j].v.push_back(i),d[j].cnt++;
  	if(is[i]) cnt++;
  }
  printf("%d ",cnt),cnt=0;
  for(int i=1;i<=m;i++) {
  	sort(d+i,d+m+1,[](Detect a,Detect b) { return a.cnt>b.cnt; });
  	bool flag=false;
  	for(auto j:d[i].v) if(!vis[j]&&is[j]) vis[j]=true,flag=true;
  	if(flag) cnt++;
  	for(int j=i+1;j<=m;j++) {
  	  d[j].cnt=0;
  	  for(auto k:d[j].v) if(!vis[k]&&is[k]) d[j].cnt++;
	}
  }
  printf("%d\n",m-cnt);
  for(int i=1;i<=n;i++) vis[i]=false,is[i]=false;
  for(int i=1;i<=m;i++) d[i].v.clear(),d[i].cnt=0;
}
int main() {
  freopen("detect.in","r",stdin);
  freopen("detect.out","w",stdout);
  int t; scanf("%d",&t);
  while(t--) solve();
  return 0;
}
