#include <bits/stdc++.h>
using namespace std;

int ques;
int n, m, k;
int x, y, d;
char a[1010][1010];
bool f[1010][1010];
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d",&ques);

    for(int qu = 1; qu <= ques; qu++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
        }}

        memset(f, 0, sizeof(f));
        int ans = 1;
        f[x][y] = true;
        for(int step = 1; step <= k; step ++){
            int tx = x + fx[d];
            int ty = y + fy[d];

            if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == '.'){
                x = tx;
                y = ty;
            }else{
                d = (d+1) % 4;
            }

            if(f[x][y] == false){
                ans ++;
                f[x][y] = true;
            }
        }
        cout << ans << endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
