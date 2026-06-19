#include <iostream>
using namespace std;

int t,n,m,k,x,y,d,cnt=1;
char forest[10010][10010];
const int dir[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin>>t;
    for(int _=0;_<t;_++){
        cnt=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>forest[i][j];
            }
        }
        forest[x][y]=',';
        for(int i=1;i<=k;i++){
            //printf("%d: (%d, %d) dir %d forest %c \n", k, x, y, d, forest[x][y]);
            if(forest[x+dir[d][0]][y+dir[d][1]] != 'x' && x+dir[d][0]>=1 && x+dir[d][0]<=n && \
                  y+dir[d][1]>=1 && y+dir[d][1]<=m)
            {
                x+=dir[d][0];
                y+=dir[d][1];
                if(forest[x][y]=='.'){
                    cnt++;
                    forest[x][y]=',';
                }
                //printf("%d, %d\n",x,y);
            }

            else{
                d+=1;
                d%=4;
                //cout << "向右转\n";
            }
        }

        cout << cnt << endl;
      //  cnt=1;
    }

    return 0;
}
