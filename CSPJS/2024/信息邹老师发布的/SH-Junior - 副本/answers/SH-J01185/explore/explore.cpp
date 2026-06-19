#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("explore.in","r",stdin);
	freopen ("explore.out","w",stdout);
	int t;
	cin >>t;
	char s;
	for (int i=0;i<t;++i)
	{
		int n,m,k,x,y,ans=0,d,a=0;
		cin >>n>>m>>k>>x>>y>>d;
		for (i=0;i<m*n;++i)
		{
			cin >>s;
			if (s=='x') a=1;
		}
		if (a==1)
		{
			cout <<d;continue;
		}
		if (x==1||y==1||x==n||y==m)
		{
			ans=2*n+2*m-4;if (d<ans) cout <<d<<endl;continue;
		}
		if (d==0) ans=n-x-5+n+n+m+m;
		if (d==1) ans=m-y-5+n+n+m+m;
		if (d==2) ans=y-6+n+n+m+m;
		if (d==3) ans=x-6+n+n+m+m;
		if (d<ans) cout <<d<<endl;
		else cout <<ans;
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >>t;
	for (int i=0;i<t;++i)
	{
		int n,m,k,x,y,ans=0,d;
		cin >>n>>m>>k>>x>>y>>d;d++;x--;y--;
		char s[n][m];int a[n][m][3]={0};
		for (int j=0;j<n;++j) for (int ii=0;ii<m;++ii) cin >>s[j][ii];
		for (int j=0;j<k;++j)
		{
			if (d==1)
			{
				y+=1;
				if (s[x][y]=='x'||x<0||x>n||y<0||y>m)
				{
					y--;d=2;j--;continue;
				}	
				if (a[x][y-1][0]==1) break;
				if (a[x][y][0]==a[x][y][1]==a[x][y][2]==a[x][y][3]==0)
				{
					ans++,a[x][y][0]==1;
				}
				continue;
			}
			if (d==2)
			{
				x+=1;
				if (s[x][y]=='x'||x<0||x>n||y<0||y>m)
				{
					x--;d=3;j--;continue;
				}
				if (a[x-1][y][1]==2) break;
				if (a[x][y][0]==a[x][y][1]==a[x][y][2]==a[x][y][3]==0) 
				{
					ans++,a[x][y][1]==2;
				}
				continue;
			}
			if (d==3)
			{
				y-=1;
				if (s[x][y]=='x'||x<0||x>n||y<0||y>m)
				{
					y++;d=4;j--;continue;
				}
				if (a[x][y+1][2]==3) break;
				if (a[x][y][0]==a[x][y][1]==a[x][y][2]==a[x][y][3]==0) 
				{
					ans++,a[x][y][2]==3;
				}
				continue;
			}
			if (d==4)
			{
				x-=1;
				if (s[x][y]=='x'||x<0||x>n||y<0||y>m)
				{
					x++;d=1;j--;continue;
				}	
				if (a[x+1][y][3]==4) break;
				if (a[x][y][0]==a[x][y][1]==a[x][y][2]==a[x][y][3]==0)
				{
					ans++,a[x][y][3]==4;
				}
				continue;
			}
		}
		cout <<ans+1<<endl;
	}
	return 0;
}*/
