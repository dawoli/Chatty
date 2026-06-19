#include <iostream>
using namespace std;
char map[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d;
    cin>>T;
    for (int i=0;i<T;i++) {
        cin>>n>>m>>k>>x>>y>>d;
        for (int j=0;j<n;j++) {
            for (int a=0;a<m;a++) {
                cin>>map[j][a];
            }
        }
        x--;
        y--;
        int ans=1;
        int x2,y2;
        for (int j=0;j<k;j++) {
            if (d==0) {
                x2=x;
                y2=y+1;
            } else if (d==1) {
                x2=x+1;
                y2=y;
            } else if (d==2) {
                x2=x;
                y2=y-1;
            } else if (d==3) {
                x2=x-1;
                y2=y;
            }
            if (x2<n && x2>=0 && y2>=0 && y2<m && map[x2][y2]!='x') {
                if (map[x2][y2]=='.') {
                    ans++;
                }
                x=x2;
                y=y2;
                map[x][y]='0';
            } else {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
