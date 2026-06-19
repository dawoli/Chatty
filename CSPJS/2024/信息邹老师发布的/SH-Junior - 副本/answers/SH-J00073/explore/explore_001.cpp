#include <bits/stdc++.h>
using namespace std;
int n,m;
char mapp[1020][1020];
bool mappp[1020][1020];
int k,k1=0,ans=0,kx,ky,dd;
bool booll=false;
void dfs(int x,int y,int d)
{
    k1++;
    mappp[x][y]=true;
    if(k1==k)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if(mappp[i][j]==true)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        k1=0,ans=0;
        for (int i=1;i<=1005;i++)
        {
            for (int j=1;j<=1005;j++)
            {
                mappp[i][j]=false;
            }
        }
        return;
    }

    if(d==0)
    {
        if((x<1)||(x>n)||(y+1<1)||(y+1>m))
        {
            d=(d+1)%4;
            booll=true;
            dfs(x,y,d);
        }
        else
        {
            if(mapp[x][y+1]=='x')
            {
                d=(d+1)%4;
                booll=true;
                dfs(x,y,d);
            }
            else
            {
				if(booll==true)
				{
					k1--;
					booll=false;
				}
                mappp[x][y+1]=true;
                dfs(x,y+1,d);
            }
        }
    }
    else if(d==1)
    {
        if((x+1<1)||(x+1>n)||(y<1)||(y>m))
        {
            d=(d+1)%4;
            booll=true;
            dfs(x,y,d);
        }
        else
        {
            if(mapp[x+1][y]=='x')
            {
                d=(d+1)%4;
                booll=true;
                dfs(x,y,d);
            }
            else
            {
				if(booll==true)
				{
					k1--;
					booll=false;
				}
                mappp[x+1][y]=true;
                dfs(x+1,y,d);

            }
        }
    }
    else if(d==2)
    {
        if((x<1)||(x>n)||(y-1<1)||(y-1>m))
        {
            d=(d+1)%4;
            booll=true;
            dfs(x,y,d);
        }
        else
        {
            if(mapp[x][y-1]=='x')
            {
                d=(d+1)%4;
                booll=true;
                dfs(x,y,d);
            }
            else
            {
				if(booll==true)
				{
					k1--;
					booll=false;
				}
                mappp[x][y-1]=true;
                dfs(x,y-1,d);
            }
        }
    }
    else if(d==3)
    {
        if((x-1<1)||(x-1>n)||(y<1)||(y>m))
        {
            d=(d+1)%4;
            booll=true;
            dfs(x,y,d);
        }
        else
        {
            if(mapp[x-1][y]=='x')
            {
                d=(d+1)%4;
                booll=true;
                dfs(x,y,d);
            }
            else
            {
				if(booll==true)
				{
					k1--;
					booll=false;
				}
                mappp[x-1][y]=true;
                dfs(x-1,y,d);
            }
        }
    }
}
int main()
{
    freopen("r","explore.in",stdin);
    freopen("w","explore.out",stdout);
    int T;
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>kx>>ky>>dd;
        for (int j=1;j<=n;j++)
        {
            for (int kk=1;kk<=m;kk++)
            {
                cin>>mapp[j][kk];
            }
        }
        mappp[kx][ky]=true;
        dfs(kx,ky,dd);
    }
    return 0;
}
