#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,xx,yy,dd,a,b,c,s[1001][1001]={0},sum;
char mp[1001][1001];
int f(int x,int y,int d){
	if(d==0)
	{
		y++;
	}
	if(d==2)
	{
		y--;
	}
	if(d==1)
	{
		x++;
	}
	if(d==3)
	{
		x--;
	}
	if(x<0||y<0||x>=n||y>=m)
	{
		c++;c%=4;
		return 0;
	}
	if(mp[x][y]=='.')
	{
		a=x;b=y;c=d;
		s[x][y]++;
		return 0;
	}
	else
	{
		c++;c%=4;
		return 0;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		sum=0;
		cin>>n>>m>>k>>xx>>yy>>dd;
		for(int i=0;i<=n-1;i++)
		{
			cin>>mp[i];
		}
		a=xx-1;
		b=yy-1;
		c=dd;
		s[a][b]++;
		for(int i=1;i<=k;i++)
		{
			f(a,b,c);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(s[i][j]>0)
				{
					sum++;
					s[i][j]=0;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
