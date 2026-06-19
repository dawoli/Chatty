#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char arr[1001][1001];
int brr[1001][1001],q[100000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int m,n,k,x,y,chao,num=1;
        cin>>m>>n>>k;
        cin>>x>>y>>chao;
        for(int j=1;j<=m;j++)
        {
            for(int z=1;z<=n;z++)
            {
                cin>>arr[j][z];
            }
        }
        for(int j=1;j<=m;j++)
        {
            for(int z=1;z<=n;z++)
            {
                brr[j][z]=0;
            }
        }
        for(int j=1;j<=k;j++)
        {
            if(chao==0)
            {
                int xx=x,yy=y+1;
                if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&arr[xx][yy]!='x')
                {
                    brr[xx][yy]=1;
                    x=xx;
					y=yy;
					continue;
                }
                else 
				{
					chao=(chao+1)%4;
					
					continue;
				}
            }
            else if(chao==1)
            {
                int xx=x+1,yy=y;
                if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&arr[xx][yy]!='x')
                {
                    brr[xx][yy]=1;
                    x=xx;
					y=yy;
					
					continue;
                }
                else 
				{
					chao=(chao+1)%4;
					continue;
				}
            }
            else if(chao==2)
            {
                int xx=x,yy=y-1;
                if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&arr[xx][yy]!='x')
                {
                    brr[xx][yy]=1;
                    x=xx;
					y=yy;
					continue;
                }
                else 
				{
					chao=(chao+1)%4;
					continue;
				}
            }
            else if(chao==3)
            {
                int xx=x-1,yy=y;
                if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&arr[xx][yy]!='x')
                {   
                    brr[xx][yy]=1;
                    x=xx;
					y=yy;
					continue;
                }
                else 
				{
					chao=(chao+1)%4;
				continue;
				}
            }
        }
       	for(int j=1;j<=m;j++)
        {
            for(int z=1;z<=n;z++)
            {
                if(brr[j][z]==1)
                {
                	num++;
				}
            }
        }
        q[i]=num;
    }
    for(int i=1;i<=t;i++)
    {
    	cout<<q[i]<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}