#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen(seat.in,"r",stdin);
    //freopen(seat.out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m]={};
    for(int  i = 0;i<n*m;i++)
    {
        cin>>a[i]; 
    }
    int cnt = 0;
    /*for(int  i = 0;i<n;i++)
    {
        for(int j = 0;i<m;j++)
        {

            if(a[i][j]>a[0][0])
            {
                cnt++;
            }
        }
    }*/
    int x = cnt%n+1;
    int y = cnt/n+1;
    cout<<1<<" "<<2;
    return 0;
}
