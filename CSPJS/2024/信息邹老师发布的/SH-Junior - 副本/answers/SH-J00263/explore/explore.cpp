#include <bits/stdc++.h>
using namespace std;
int d[4][2]={0,1,1,0,0,-1,-1,0};
int ma[1000][1000];
int b[1000][1000];
long long c=0;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int nn;
	cin>>nn;
	for(int q=0;q<nn;q++)
	{
		int n,m,k,x,y,dd;
		cin>>n>>m>>k>>x>>y>>dd;
		x--;y--;
		for(int i=0;i<n;i++)
		{
			string map;
			cin>>map;
			for(int j=0;j<m;j++)
			{
				if(map[j]=='x')ma[i][j]=1;
				else ma[i][j]=0;
				b[i][j]=0;
			}
		}
		b[x][y]=1;c=1;
		for(int i=0;i<k;i++)
		{
			int x1=x+d[dd][0],y1=y+d[dd][1];
			if(x1<0||x1>=n||y1<0||y1>=m||ma[x1][y1])
			{
				dd=(dd+1)%4;
				continue;
			}
			x=x1,y=y1;
			if(b[x][y]==0)
			{
				c++;b[x][y]=1;
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
