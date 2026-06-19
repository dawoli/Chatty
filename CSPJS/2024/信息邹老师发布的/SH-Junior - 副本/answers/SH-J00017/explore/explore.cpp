#include<bits/stdc++.h>
using namespace std;
int a[1003][1003]={0},b[1003][1003]={0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int n,x1,y1,c,x,y,d,s=1,t;
	char v;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int i=0;i<1004;i++)
		{
			for(int j=0;j<1004;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=0;i<1004;i++)
		{
			for(int j=0;j<1004;j++)
			{
				b[i][j]=0;
			}
		}
		b[1][1]=1;
		s=0;
		cin>>x1>>y1>>c;
		cin>>x>>y>>d;
		for(int j=1;j<=x1;j++)
		{
			for(int k=1;k<=y1;k++)
			{
				cin>>v;
				if(v=='.')a[j][k]=1;
				else a[j][k]=0;
			}
		}
		t=0;
		for(int j=0;j<c;j++)
		{
			if(d==0)
			{
				if(a[x][y+1])
				{
					y+=1;
					t=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==1)
			{
				if(a[x+1][y])
				{
					x+=1;
					t=1;
				}
				else
				{
					d=(d+1)%4;
				}	
			}
			else if(d==2)
			{
				if(a[x][y-1])
				{
					y-=1;
					t=1;
				}
				else
				{
					d=(d+1)%4;
				}	
			}
			else if(d==3)
			{
				if(a[x-1][y])
				{
					x-=1;
					t=1;
				}
				else
				{
					d=(d+1)%4;
				}	
			}
			if(b[x][y]==0&&t==1)
			{
				
				b[x][y]=1;
				t=0;
			}
			
			
		}
		for(int j=1;j<=x1;j++)
			{
				for(int k=1;k<=y1;k++)
				{
					if(b[j][k])
					{
						s++;
					}
				}
			}
		printf("%d\n",s);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
