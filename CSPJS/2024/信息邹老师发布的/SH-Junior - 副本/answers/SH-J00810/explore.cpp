#include<iostream>
#include<cstdio> 
#define ll long long
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int qn;
	cin>>qn;
	int fx[4]={0,1,0,-1};
	int fy[4]={1,0,-1,0};
	for(int t=1;t<=qn;t++)
	{
		int m,n,times_direc,sum=1;
		cin>>m>>n>>times_direc;
		int pos_x,pos_y,direc;
		char gph[m+1][n+1]={0};
		cin>>pos_x>>pos_y>>direc;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>gph[i][j];
			}
		}
		gph[pos_x][pos_y]='1';
		for(int i=1;i<=times_direc;i++)
		{
			if((pos_x+fx[direc]<1)||(pos_y+fy[direc]<1)||(pos_x+fx[direc]>m)||(pos_y+fy[direc]>n))
			{
				direc+=1;
				direc%=4;
				continue;				
			}
			else if(gph[pos_x+fx[direc]][pos_y+fy[direc]]=='x')
			{
				direc+=1;
				direc%=4;
				continue;
			}
			else if(gph[pos_x+fx[direc]][pos_y+fy[direc]]=='1')
			{
				pos_x+=fx[direc];
				pos_y+=fy[direc];
				continue;			
			}
			else if(gph[pos_x+fx[direc]][pos_y+fy[direc]]=='.')
			{
				sum++;
				gph[pos_x+fx[direc]][pos_y+fy[direc]]='1';
				pos_x+=fx[direc];
				pos_y+=fy[direc];
				continue;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
