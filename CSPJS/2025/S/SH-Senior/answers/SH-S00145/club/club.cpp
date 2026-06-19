#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5, M = 5;
int t, n, m, ans, cnt[M];
struct node{
    int x, y, z, maxid;
    bool operator< (const node &b) const{
        return x - y < b.x - b.y;
    }
}a[N], b[N];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        m = ans = 0;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            if (a[i].x >= a[i].y && a[i].x >= a[i].z){
                a[i].maxid = 1;
            }
            else if (a[i].y >= a[i].x && a[i].y >= a[i].z){
                a[i].maxid = 2;
                swap(a[i].x, a[i].y);
            }
            else{
                a[i].maxid = 3;
                swap(a[i].x, a[i].z);
            }
            if (a[i].y < a[i].z){
                swap(a[i].y, a[i].z);
            }
            cnt[a[i].maxid]++;
            ans += a[i].x;
        }
        int posid = 0;
        for (int i = 1; i <= 3; i++){
            if (cnt[i] >= n / 2){
                posid = i;
                break;
            }
        }
        if (!posid){
            printf("%d\n", ans);
            continue;
        }
        for (int i = 1; i <= n; i++){
            if (a[i].maxid == posid){
                b[++m] = a[i];
            }
        }
        sort(b + 1, b + m + 1);
        for (int i = 1; i <= m - n / 2; i++){
            ans -= (b[i].x - b[i].y);
        }
        printf("%d\n", ans);
    }
}