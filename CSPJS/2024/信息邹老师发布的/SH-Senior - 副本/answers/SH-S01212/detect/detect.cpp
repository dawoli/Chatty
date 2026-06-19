#include <bits/stdc++.h>
using namespace std;

using ull=uint64_t;
using ll=int64_t;

int d[100005], v[100005], a[100005], p[100005];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  freopen("detect.in", "r", stdin);
  freopen("detect.out", "w", stdout);

  int T; cin>>T;
  while (T--) {
    int n, m, l, ve; cin>>n>>m>>l>>ve;
    for (int i=0; i<n; ++i) cin>>d[i]>>v[i]>>a[i];
    for (int i=0; i<m; ++i) cin>>p[i];
    int lm=p[m-1];
    ull vl=ull(ve)*ve;
    int cnt=0;
    for (int i=0; i<n; ++i) {
      if (d[i]>lm) continue;
      ull v2=ull(v[i])*v[i]+2*ull(a[i])*(lm-d[i]);
      if (v2>vl) ++cnt;
    }
    cout<<cnt<<" "<<(cnt==0?m:m-1)<<"\n";
  }

  return 0;
}
