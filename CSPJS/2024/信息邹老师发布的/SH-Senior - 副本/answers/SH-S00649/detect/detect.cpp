#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, m, L, V, d[100010], v[100010], a[100010], p[100010];
bool detect[100010];
int ans1, ans2, maxpos;
struct violate {
    int lmost, rmost;
} cars[100010];
bool cmp(violate a, violate b) {
    return a.rmost < b.rmost;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
for(int times = 1; times <= T; ++times) {
    scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
    memset(cars, 0, sizeof(cars));
    memset(d, 0, sizeof(d));
    memset(v, 0, sizeof(v));
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    memset(detect, 0, sizeof(detect));
    ans1 = 0; ans2 = 0; maxpos = 0;
    for(int i = 1; i <= n; ++i) scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%lld", &p[i]);
    for(int i = 1; i <= n; ++i) {
        if(d[i] > p[m]) continue;
        if(a[i] >= 0) {
            ll v1 = v[i] * v[i] + 2 * a[i] * (p[m] - d[i]);
            if(v1 <= V * V) continue;
            //printf("Car %d: v1^2=%lld, V^2=%lld, violation\n", i, v1, V * V);
            ++ans1;
            detect[i] = true; cars[ans1].rmost = m;
            int l = 1, r = m, mid;
            while(l < r) {
                mid = (l + r) >> 1;
                if(V * V < v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]) && p[mid] >= d[i]) r = mid;
                else l = mid + 1;
            }
            cars[ans1].lmost = l;
            //printf("Car %d: lmost=%d, rmost=%d\n", i, cars[ans1].lmost, cars[ans1].rmost);
        } else {
            int l1 = 1, r1 = m, mid1;
            while(l1 < r1) {
                mid1 = (l1 + r1 + 1) >> 1;
                //printf("%d %d %d\n", l1, r1, mid1);
                if(V * V < v[i] * v[i] + 2 * a[i] * (p[mid1] - d[i])) l1 = mid1;
                else r1 = mid1 - 1;
            }
            if(p[r1] < d[i]) continue;
            if(V * V >= v[i] * v[i] + 2 * a[i] * (p[r1] - d[i])) continue;
            //printf("Car %d: v1^2=%lld, V^2=%lld, violation at checkpoint %lld\n", i, v[i] * v[i] + 2 * a[i] * (p[r1] - d[i]), V * V, p[r1]);
            detect[i] = true; ++ans1;
            cars[ans1].rmost = r1;
            int l = 1, r = m, mid;
            while(l < r) {
                mid = (l + r) >> 1;
                if(p[mid] >= d[i]) r = mid;
                else l = mid + 1;
            }
            cars[ans1].lmost = l;
            //printf("Car %d: lmost=%d, rmost=%d\n", i, cars[ans1].lmost, cars[ans1].rmost);
        }
    }
    sort(cars + 1, cars + ans1 + 1, cmp);
    for(int i = 1; i <= ans1; ++i) {
        if(cars[i].lmost > maxpos) {
            ++ans2;
            maxpos = cars[i].rmost;
        }
    }
    printf("%d %lld\n", ans1, m - ans2);
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}