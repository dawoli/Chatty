#include <iostream>
#include <cstring>
using namespace std;
struct s
{
	int x,y,n;
};
struct node
{
	int x,y;
	s d;
}s;
bool a[1005][1005];
bool flag[1005][1005];
int n,m,k;
bool check(int x,int y)
{
	return x<=n&&y<=m&&a[x][y];
}
void f()
{
	if (s.d.n==0)
	{
		s.d.x=0;
		s.d.y=1;
	}
	if (s.d.n==1)
	{
		s.d.x=1;
		s.d.y=0;
	}
	if (s.d.n==2)
	{
		s.d.x=0;
		s.d.y=-1;
	}
	if (s.d.n==3)
	{
		s.d.x=-1;
		s.d.y=0;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		memset(flag,0,sizeof flag);
	    cin>>n>>m>>k;
        cin>>s.x>>s.y>>s.d.n;
    	f();
	    for (int i=1;i<=n;i++)
	    {
    		for (int j=1;j<=m;j++)
	    	{
		    	char c;
			    cin>>c;
			    if (c=='.') a[i][j]=1;
		    }
	    }
    	int ans=0;
    	for (int i=1;i<=k;i++)
    	{
    		int x=s.x;
    		int y=s.y;
    		if (flag[x][y]) ans--;
	    	flag[x][y]=true;
	    	ans++;
    		int dx=s.d.x;
    		int dy=s.d.y;
    		int dn=s.d.n;
    		int nx=x+dx;
	    	int ny=y+dy;
	    	if (check(nx,ny))
	    	{

	    		s.x=nx;
	    		s.y=ny;
    		}
    		else
    		{
			    s.d.n=(s.d.n+1)%4;
    			f();
    		}
    	}
    	int x=s.x;
    	int y=s.y;
    	if (flag[x][y]) ans--;
    	flag[x][y]=true;
    	ans++;
  	    cout<<ans<<endl;
    }
	return 0;
}
