#include <iostream>
#include <string>
using namespace std;

string a[6][1001],tmp;
int fx[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int num_[6];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d,num;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        num = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for (int j = 0;j < n;j++) cin >> a[i][j];
        for (int j = 0;j < k;j++)
        {
            if ((x-1+fx[d][0] == -1) || (x-1+fx[d][0] == n) || (y-1+fx[d][1] == -1) || (y-1+fx[d][1]) == m) d = (d+1)%4;
            else
            {
                tmp = a[i][x-1+fx[d][0]];
                if (tmp[y-1+fx[d][1]] == 'x')
                {
                    d = (d+1)%4;
                }
                else
                {
                    tmp = a[i][x-1];
                    tmp[y-1] = '_';
                    a[i][x-1] = tmp;
                    x += fx[d][0];
                    y += fx[d][1];
                    tmp = a[i][x-1];
                    if (tmp[y-1] == '.') num++;
                }
            }
            //for (int l = 0;l < n;l++) cout << a[i][l] << endl;
            //cout << x << ' ' << y << ' ' << num << ' ' << j << endl;
        }
        num_[i] = num;
    }
    for (int i = 0;i < T;i++) cout << num_[i] << endl;
    return 0;
}
