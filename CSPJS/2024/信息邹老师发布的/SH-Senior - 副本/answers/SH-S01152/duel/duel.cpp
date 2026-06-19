#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
unordered_map<int, int> bigger; // 表示下一个比他大的数的index
unordered_map<int, int> big;    // 表示可用的下一个比他大的数的个数
unordered_map<int, int> m;
set<int> all;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++m[a[i]];
        all.insert(a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n;)
    {
        bigger[a[i]] = i + m[a[i]];
        big[a[i]] = m[a[bigger[a[i]]]];
        i += m[a[i]];
    }
    int ans = 0;
    for (int i = 1; i <= n; i += m[a[i]]) // 若能被下一个数打死则打死，不能则使用下下个数并把下个数的big减去需要的
    {
        int tmp = i, tmpm=m[a[i]];
        while (tmpm > 0 && tmp != 0)
        {
            int minus = min(tmpm, big[a[tmp]]);
            tmpm -= minus;
            big[a[tmp]] -= minus;
            tmp = bigger[a[tmp]];
        }
        ans += tmpm;
    }
    printf("%d\n", ans);
    return 0;
}