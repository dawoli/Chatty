#include<cstdio>
#include<iostream>
using namespace std;
const int N=2e5+10; int a[N],col[N];
void solve() {
  int n; long long ans=0; scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=0;i<(1<<n);i++) {
  	for(int j=1;j<=n;j++) col[j]=(i>>(j-1))&1;
  	long long sum=0;
  	for(int j=1;j<=n;j++)
  	  for(int k=j-1;k>=1;k--)
  	    if(col[j]==col[k]) {
  	      if(a[j]==a[k]) sum+=a[j];
  	      break;
		}
	ans=max(ans,sum);
  }
  printf("%lld\n",ans);
}
int main() {
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int t; scanf("%d",&t);
  while(t--) solve();
  return 0;
}
