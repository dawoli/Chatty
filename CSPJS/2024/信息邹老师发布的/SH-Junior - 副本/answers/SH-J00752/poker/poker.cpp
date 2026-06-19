#include <bits/stdc++.h>
using namespace std;
bool a[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;//D=0,C=1,H=2,S=3
    string p;//A=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,T=10,J=11,Q=12,K=13
    cin >> n;//first=huase,second=dianshu
    int y=0;
    for (int i = 1;i<=n;i++)
    {
        y=0;
        cin >> p;
        if (p[0]=='D')
        {
            if (p[1]=='A')
            {
                a[0][0]=1;
            }
            else if (p[1]=='T')
            {
                a[0][9]=1;
            }
            else if (p[1]=='J')
            {
                a[0][10]=1;
            }
            else if (p[1]=='Q')
            {
                a[0][11]=1;
            }
            else if (p[1]=='K')
            {
                a[0][12]=1;
            }
            else
            {
                y=int(p[1])-'1';
                a[0][y]=y;
            }
        }
        else if (p[0]=='C')
        {
            if (p[1]=='A')
            {
                a[1][0]=1;
            }
            else if (p[1]=='T')
            {
                a[1][9]=1;
            }
            else if (p[1]=='J')
            {
                a[1][10]=1;
            }
            else if (p[1]=='Q')
            {
                a[1][11]=1;
            }
            else if (p[1]=='K')
            {
                a[1][12]=1;
            }
            else
            {
                y=int(p[1])-'1';
                a[1][y]=y;
            }
        }
        else if (p[0]=='H')
        {
            if (p[1]=='A')
            {
                a[2][0]=1;
            }
            else if (p[1]=='T')
            {
                a[2][9]=1;
            }
            else if (p[1]=='J')
            {
                a[2][10]=1;
            }
            else if (p[1]=='Q')
            {
                a[2][11]=1;
            }
            else if (p[1]=='K')
            {
                a[2][12]=1;
            }
            else
            {
                y=int(p[1])-'1';
                a[2][y]=y;
            }
        }
        else if (p[0]=='S')
        {
            if (p[1]=='A')
            {
                a[3][0]=1;
            }
            else if (p[1]=='T')
            {
                a[3][9]=1;
            }
            else if (p[1]=='J')
            {
                a[3][10]=1;
            }
            else if (p[1]=='Q')
            {
                a[3][11]=1;
            }
            else if (p[1]=='K')
            {
                a[3][12]=1;
            }
            else
            {
                y=int(p[1])-'1';
                a[3][y]=y;
            }
        }
    }
    int sum=0;
    for (int i = 0;i<=3;i++)
    {
        for (int j = 0;j<=12;j++)
        {
            if (a[i][j]==0)
            {
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
