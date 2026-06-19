#include<bits/stdc++.h>

using namespace std;

int T, n;
const int N = 1e5+10;
struct Will {
    int cls, love = 0, love2 = 0; // love 表示第一志愿，love2 表示第二志愿， 第三志愿永远不会选到
    const bool operator<(const Will& w) const {
        return love < w.love;
    }
    const bool operator>(const Will& w) const {
        return love > w.love;
    }
};
Will a[N]{}; 
priority_queue<Will, vector<Will>, greater<Will>> pq[4]; 

int main() {
#ifndef MYDEBUG
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
#endif

    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> n;
        pq[1] = {};
        pq[2] = {};
        pq[3] = {};
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            Will sorting[3];
            sorting[0].cls = 1;
            sorting[1].cls = 2;
            sorting[2].cls = 3;
            cin >> sorting[0].love >> sorting[1].love >> sorting[2].love;
            sort(sorting, sorting + 3); // 神秘排序
            a[i].cls = sorting[2].cls;
            a[i].love = sorting[2].love;
            a[i].love2 = sorting[1].love;
            ans += a[i].love2;
            a[i].love -= a[i].love2;
        }

        for (int i = 1; i <= n; i++) {
            int cls = a[i].cls, love = a[i].love;
            if ((int)pq[cls].size() < n / 2) { // 有空位直接上
                ans += love;
                pq[cls].push(a[i]);
                // cout << i << "case 1" << endl;
            } else if (pq[cls].top().love < love) { // 抢第一志愿
                ans += love;
                ans -= pq[cls].top().love;
                pq[cls].pop();
                pq[cls].push(a[i]);
                // cout << i << "case 2" << endl;
            } else { // 发配第二志愿
                // cout << i << "case 3" << endl;
                // cout << "top: " << pq[cls].top().love << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

// ^_^
