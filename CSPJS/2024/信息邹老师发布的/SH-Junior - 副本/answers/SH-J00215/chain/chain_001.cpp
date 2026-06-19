#include<cstdio>
#include<vector>
using namespace std;
const int N=1e5+10,R=110; int mx,n,k; vector<int>s[N]; vector<pair<int,int> >q[R]; int ans[N];
void dfs(int rd,int lstnum,int lstp) {
  if(rd>mx+1) return;
  for(auto i:q[rd]) if(i.first==lstnum) ans[i.second]=1;
  for(int i=1;i<=n;i++) {
  	if(i==lstp) continue;
  	for(int j=0;j<s[i].size();j++) {
  	  if(s[i][j]!=lstnum) continue;
  	  for(int r=j+1;r<=j+k-1&&r<s[i].size();r++) dfs(rd+1,s[i][r],i);
	}
  }
}
void solve() {
  int qq; scanf("%d %d %d",&n,&k,&qq);
  for(int i=1;i<=n;i++) {
  	int l,a; scanf("%d",&l);
  	while(l--) scanf("%d",&a),s[i].push_back(a);
  }
  mx=0;
  for(int i=1,r,c;i<=qq;i++) scanf("%d %d",&r,&c),mx=max(mx,r),q[r].push_back(make_pair(c,i));
  dfs(0,1,0);
  for(int i=1;i<=qq;i++) printf("%d\n",ans[i]),ans[i]=0;
  for(int i=1;i<=n;i++) s[i].clear();
  for(int i=1;i<=mx;i++) q[i].clear();
}
int main() {
  freopen("chain.in","r",stdin);
  freopen("chain.out","w",stdout);
  int t; scanf("%d",&t);
  while(t--) solve();
  return 0;
}
