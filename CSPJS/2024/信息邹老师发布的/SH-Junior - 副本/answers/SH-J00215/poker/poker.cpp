#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=100; string s[N];
int main() {
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  int n; cin>>n;
  for(int i=1;i<=n;i++) cin>>s[i];
  sort(s+1,s+n+1); int k=unique(s+1,s+n+1)-s-1;
  cout<<52-k;
  return 0;
}
