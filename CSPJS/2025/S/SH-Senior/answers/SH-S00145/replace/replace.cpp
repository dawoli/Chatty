#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) (x & -x)
const int N = 2e5 + 5, M = 4e6 + 5;
int n, q, maxn, ls[N], ans[N], db[N << 1], t[M];
string s1[N], s2[N], t1, t2;
struct node{
    int dx, pre, lst, id;
}a[N << 1];
void update(int k, int d){
    for (int i = k; i <= maxn; i += lowbit(i)){
        t[i] += d;
    }
}
int query(int k){
    int sum = 0;
    for (int i = k; i; i -= lowbit(i)){
        sum += t[i];
    }
    return sum;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    if (n > 100){
        for (int i = 1; i <= n; i++){
            cin >> t1 >> t2;
            int len = t1.size();
            int xb1 = 0, xb2 = 0;
            for (int j = 0; j < len; j++){
                if (t1[j] == 'b'){
                    xb1 = j;
                }
                if (t2[j] == 'b'){
                    xb2 = j;
                }
            }
            a[i] = (node){xb2 - xb1, xb1, len - xb1 - 1, 0};
        }
        int m = n;
        for (int i = 1; i <= q; i++){
            cin >> t1 >> t2;
            int l1 = t1.size(), l2 = t2.size();
            if (l1 != l2){
                continue;
            }
            int xb1 = 0, xb2 = 0;
            for (int j = 0; j < l1; j++){
                if (t1[j] == 'b'){
                    xb1 = j;
                }
                if (t2[j] == 'b'){
                    xb2 = j;
                }
            }
            a[++m] = (node){xb2 - xb1, xb1, l1 - xb1 - 1, i};
        }
        sort(a + 1, a + m + 1, [](const node &a, const node &b){
            if (a.dx != b.dx){
                return a.dx < b.dx;
            }
            if (a.pre != b.pre){
                return a.pre < b.pre;
            }
            if (a.lst != b.lst){
                return a.lst < b.lst;
            }
            return a.id < b.id;
        });
        for (int i = 1; i <= m; i++){
            db[i] = a[i].dx;
            maxn = max(maxn, a[i].lst + 1);
        }
        for (int i = 1; i <= m; i++){
            int l = i, r = upper_bound(db + 1, db + m + 1, a[i].dx) - db - 1;
            memset(t, 0, sizeof(t));
            for (int j = l; j <= r; j++){
                if (a[j].id){
                    int pos = query(a[j].lst + 1);
                    ans[a[j].id] = pos;
                }
                else{
                    update(a[j].lst + 1, 1);
                }
            }
            i = r;
        }
        for (int i = 1; i <= q; i++){
            cout << ans[i] << '\n';
        }
        return 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
        ls[i] = s1[i].size();
    }
    while (q--){
        int sum = 0;
        cin >> t1 >> t2;
        int l1 = t1.size(), l2 = t2.size();
        if (l1 != l2){
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= n; i++){
            bool flag = false;
            for (int j = 0; j + ls[i] - 1 < l1; j++){
                string p1 = t1.substr(0, j), p2 = t1.substr(j, ls[i]), p3 = t1.substr(j + ls[i], l1 - j - ls[i]);
                if (p2 == s1[i] && p1 + s2[i] + p3 == t2){
                    flag = true;
                    break;
                }
            }
            if (flag){
                sum++;
            }
        }
        cout << sum << '\n';
    }
}