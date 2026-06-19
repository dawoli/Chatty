//club
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n, a[N][3];
int b[N][2];

int calc(int x, int y, int z){
    int c0 = 0, c1 = 0;
    int ans = 0;
    vector<int> aa, bb;
    for(int i = 1; i <= n; ++ i){
        b[i][0] = a[i][x];
        b[i][1] = max(a[i][y], a[i][z]);
        if(b[i][0] >= b[i][1]){
            ++ c0;
            ans += b[i][0];
            aa.push_back(b[i][0] - b[i][1]);
        } else {
            ++ c1;
            ans += b[i][1];
            bb.push_back(b[i][1] - b[i][0]);
        }
    }
    if(c0 > c1){
        sort(aa.begin(), aa.end());
        for(int i = 0; i < (c0 - c1) / 2; ++ i){
            ans -= aa[i];
        }
    } else {
        sort(bb.begin(), bb.end());
        for(int i = 0; i < (c1 - c0) / 2; ++ i){
            ans -= bb[i];
        }
    }
    return ans;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int c0 = 0, c1 = 0, c2 = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++ i){
            for(int j = 0; j < 3; ++ j){
                scanf("%d", &a[i][j]);
            }
            if(a[i][0] >= max(a[i][1], a[i][2])){
                ++ c0;
                ans += a[i][0];
            } else if(a[i][1] >= max(a[i][0], a[i][2])){
                ++ c1;
                ans += a[i][1];
            } else {
                ++ c2;
                ans += a[i][2];
            }
        }
        if(c0 <= n/2 && c1 <= n/2 && c2 <= n/2){
            printf("%d\n", ans);
        } else if(c0 > n / 2){
            printf("%d\n", calc(0, 1, 2));
        } else if(c1 > n / 2){
            printf("%d\n", calc(1, 0, 2));
        } else if(c2 > n / 2){
            printf("%d\n", calc(2, 0, 1));
        }
    }
    return 0;
}