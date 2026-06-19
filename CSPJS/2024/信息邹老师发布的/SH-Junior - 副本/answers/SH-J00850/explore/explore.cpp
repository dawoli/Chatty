#include<iostream>
using namespace std;

char a[1010][1010];
bool b[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
            }
        }
        int cnt=1;
        int x2,y2;
        while(k--)
        {
            if(d==0)
            {
                x2=x;
                y2=y+1;
            }
            else if(d==1)
            {
                x2=x+1;
                y2=y;
            }
            else if(d==2)
            {
                x2=x;
                y2=y-1;
            }
            else
            {
                x2=x-1;
                y2=y;
            }
            if(a[x2][y2]=='x' || x2<1 || y2<1 || x2>n || y2>m) d=(d+1)%4;
            else
            {
                if(!b[x2][y2])
                {
                    cnt++;
                    b[x2][y2]=true;
                }
                x=x2;
                y=y2;
            }
        }
        cout << cnt << endl;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=m;j++)
            {
                b[i][j]=0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
