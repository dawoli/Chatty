#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int r,c,n,sx,sy;
    char a[51][51],b[1001];
    int mx[4]={0,0,-1,1};//N,S,W,E
    int my[4]={1,-1,0,0};
    string s;
    queue<pair<int,int>> q;
    void dfs(int x,int y,int now)
    {
        if(now>n)
        {
            a[x][y]='*';
        }
        int nowx=x,nowy=y;
        switch(b[now])
        {
        case 'N':
            nowx+=mx[0],nowy+=my[0];
            while(a[nowx][nowy]!='X'&&1<=nowx&&nowx<=r&&1<=nowy&&nowy<=c)
            {
                dfs(nowx,nowy,now+1);
                nowx+=mx[0],nowy+=my[0];
            }
            break;
        case 'S':
            nowx+=mx[1],nowy+=my[1];
            while(a[nowx][nowy]!='X'&&1<=nowx&&nowx<=r&&1<=nowy&&nowy<=c)
            {
                dfs(nowx,nowy,now+1);
                nowx+=mx[1],nowy+=my[1];
            }
            break;
        case 'W':
            nowx+=mx[2],nowy+=my[2];
            while(a[nowx][nowy]!='X'&&1<=nowx&&nowx<=r&&1<=nowy&&nowy<=c)
            {
                dfs(nowx,nowy,now+1);
                nowx+=mx[2],nowy+=my[2];
            }
            break;
        case 'E':
            nowx+=mx[3],nowy+=my[3];
            while(a[nowx][nowy]!='X'&&1<=nowx&&nowx<=r&&1<=nowy&&nowy<=c)
            {
                dfs(nowx,nowy,now+1);
                nowx+=mx[3],nowy+=my[3];
            }
            break;                                    
        }
    }
    void Soar()
    {
        cin>>r>>c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='*')sx=i,sy=j,a[i][j]='.';
            }
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            b[i]=s[0];
        }
        dfs(sx,sy,1);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
                cout<<a[i][j];
            cout<<endl;
        }
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}