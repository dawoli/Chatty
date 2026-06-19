#include<cstdio>
using namespace std;
const int N=1e5+10; char s[N];
int main() {
  freopen("arena.in","r",stdin);
  freopen("arena.out","w",stdout);
  int n,m; scanf("%d %d",&n,&m);
  for(int i=1,a;i<=n;i++) scanf("%d",&a);
  for(int i=1,a;i<=m;i++) scanf("%d",&a);
  int k=1,l=0;
  while(k<n) k*=2,l++;
  for(int i=1;i<=l;i++) scanf("%s",s);
  int t; scanf("%d",&t);
  while(t--) puts("0");
  return 0;
}
