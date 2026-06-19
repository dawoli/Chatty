#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[100010],cnt[100010],vis[100010],ans;

// priority_queue<int,vector<int>,greater<int> > heap;
set<int> heap;  // 模拟去重堆
queue<int> unbrk;  // 没有除尽的入队等待下次处理

signed main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    ans = n;
    for (int i=1; i<=n; ++i) {
        scanf("%lld",&a[i]);
        heap.insert(a[i]);
        ++cnt[a[i]];
    }
    // sort(a+1,a+n+1);
    unbrk.push(*heap.begin()), heap.erase(heap.begin());
    for (auto r : heap) {
        while (!unbrk.empty() and cnt[r] - vis[r] > 0) {
            int u = unbrk.front();
            if (cnt[r] - vis[r] >= cnt[u]) {  // 小的除尽
                ans -= cnt[u];
                cnt[u] = 0;
                unbrk.pop();
            } else {  // 小的没除尽
                ans -= cnt[r] - vis[r];
                cnt[u] -= cnt[r] - vis[r];
                vis[r] = cnt[r];
            }
        }
        unbrk.push(r);
    }
    printf("%lld\n",ans);
    return 0;
}