#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int T = 0;
int step = 1;
bool visited[1500][1500];
int n[10],m[10],k[10];
int x0[10],y0[10],d[10];
string s[10][MAXN];
void get()
{
	for(int i=1;i<=T;i++)
	{
		for(int g=1;g<=x0[i];g++)
		{
			for(int h=1;h<=y0[i];h++)
			{
				visited[g][h]==false;
			}
		}
	}
}
void Movements(int i,int x0,int y0)
{
	for(int p=0;p<k[i];p++)
	{
		if(d[i]==0)
	    {
			if(s[i][x0][y0+1]=='x'||y0+1>m[i])
			{
				d[i]=(d[i]+1)%4;
				continue;
			} 
			y0++;
			if(!visited[x0][y0+1]) step++;
			visited[x0][y0+1]=true;
			continue;
		}
		else if(d[i]==1)
		{
			if(s[i][x0+1][y0]=='x'||x0+1>n[i])
			{
				d[i]=(d[i]+1)%4;
				continue;
			}
			x0++;
			if(!visited[x0+1][y0]) step++;
			visited[x0+1][y0]=true;
			continue;
		}
		else if(d[i]==2)
		{
			if(s[i][x0][y0-1]=='x'||y0-1<1)
			{
				d[i]=(d[i]+1)%4;
				continue;
			} 
			y0--;
			if(!visited[x0][y0-1]) step++;
			visited[x0][y0-1]=true;
			continue;
		}
		else
		{
			if(s[i][x0-1][y0]=='x'||x0-1<1)
			{
				d[i]=(d[i]+1)%4;
				continue;
			} 
			x0--;
			if(!visited[x0-1][y0]) step++;
			visited[x0-1][y0]=true;
			continue;
		}
	}
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%i",&T);
	for(int i=1;i<=T;i++)
	{
		cin>>n[i]>>m[i]>>k[i];
		cin>>x0[i]>>y0[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=T;i++)
	{
		for(int g=1;g<=x0[i];g++)
		{
			for(int h=1;h<=y0[i];h++)
			{
				visited[g][h]==false;
			}
		}
	}
	for(int i=1;i<=T;i++)
	{
		Movements(i,x0[i],y0[i]);
		get();
		cout<<step<<endl;
		step = 1;
	}
	return 0;
}
