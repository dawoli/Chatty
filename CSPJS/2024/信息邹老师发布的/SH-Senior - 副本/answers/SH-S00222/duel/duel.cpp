#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int N=1e5+10; int a[N];
int main() {
  freopen("duel.in","r",stdin);
  freopen("duel.out","w",stdout);
  int n; scanf("%d",&n); multiset<int>s;
  for(int i=1;i<=n;i++) scanf("%d",&a[i]),s.insert(a[i]);
  sort(a+1,a+n+1); int cnt=0;
  for(int i=1;i<=n;i++) {
  	multiset<int>::iterator it=s.upper_bound(a[i]);
  	if(it==s.end()) continue;
  	multiset<int>::iterator it2=it; it++;
  	multiset<int>::iterator it3=it;
  	s.erase(it2,it3),cnt++;
  }
  printf("%d",n-cnt);
  return 0;
}
