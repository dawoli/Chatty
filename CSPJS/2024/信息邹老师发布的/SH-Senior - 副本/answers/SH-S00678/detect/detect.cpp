#include <bits/stdc++.h>
using namespace std;
bool lst;
int t, n, m, l, r, dist, cnt, st;
long long limit;
int d[100009], p[100009];
long long v[100009], a[100009];
set < pair <int, int> > range;
set < pair <int, int> > :: iterator it;
long long velocity(int i, int s) {
    return max(0LL, v[i] * v[i] + 2LL * a[i] * s);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d %d %lld", &n, &m, &dist, &limit);
        limit *= limit;
        for(int i = 1; i <= n; i++) {
            scanf("%d %lld %lld", d + i, v + i, a + i);
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d", p + i);
        }
        cnt = 0;
        lst = false;
        range.clear();
        range.insert(make_pair(1, m));
        for(int i = 1; i <= n; i++) {
            st = lower_bound(p + 1, p + m + 1, d[i]) - p;
            l = st;
            r = m;
            if(l > r)
                continue;
            if(a[i] < 0 && velocity(i, p[l] - d[i]) <= limit)
                continue;
            if(a[i] >= 0 && velocity(i, p[r] - d[i]) <= limit)
                continue;
            cnt++;
            if(a[i] >= 0) {
                lst = true;
                continue;
            }
            while(l <= r) {
                int mid = (l + r) / 2;
                if(velocity(i, p[mid] - d[i]) > limit)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            l = st;
            it = range.lower_bound(make_pair(l, m + 1));
            it--;
            if(it -> second >= l && it -> first <= r) {
                l = max(l, it -> first);
                r = min(r, it -> second);
                range.erase(it);
                range.insert(make_pair(l, r));
                continue;
            }
            it = range.lower_bound(make_pair(r, m + 1));
            it--;
            if(it -> second >= r && l <= it -> second) {
                l = max(l, it -> first);
                r = min(r, it -> second);
                range.erase(it);
                range.insert(make_pair(l, r));
                continue;
            }
            range.insert(make_pair(l, r));
        }
        if(cnt == 0)
            printf("0 %d\n", m);
        else if(lst && ((--range.end()) -> second) != m)
            printf("%d %d\n", cnt, m - range.size() - 1);
        else
            printf("%d %d\n", cnt, m - range.size());
    }
    return 0;
}