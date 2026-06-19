#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[1010][1010];
bool flag[1010][1010] = {0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.our","w",stdout);
    int t;
    cin >> t;
    while (t--){
        int n,m,k,x,y,d;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char c;
                scanf("%c",&c);
                if (c != '.' && c != 'x'){
                    j--;
                    continue;
                }
                if (c == '.') a[i][j] = 0;
                else a[i][j] = 1;
            }
        }
        memset(flag,0,sizeof(flag));
        flag[x][y] = true;
        int cnt = 1;
        while (k--){
            if (d == 0 && x<= n && x > 0 && y > 0 && y + 1 <= m && a[x][y + 1] == 0) {
                y++;
                if (!flag[x][y]) {
                    cnt++;
                    flag[x][y] = true;
                }
                continue;
            }
            if (d == 1 && x + 1<= n && x > 0 && y > 0 && y  <= m&& a[x + 1][y] == 0){
                x++;
                if (!flag[x][y]) {
                    cnt++;
                    flag[x][y] = true;
                }
                continue;
            }
            if (d == 2 && x<= n && x > 0 && y - 1 > 0 && y - 1<= m && a[x][y - 1] == 0){
                y--;
                if (!flag[x][y]) {
                    cnt++;
                    flag[x][y] = true;
                }
                continue;
            }
            if (d == 3 && x - 1<= n && x - 1 > 0 && y > 0 && y<= m&& a[x - 1][y] == 0){
                x--;
                if (!flag[x][y]) {
                    cnt++;
                    flag[x][y] = true;
                }
                continue;
            }
            d = (d + 1) % 4;
        }
        printf("%d\n",cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
