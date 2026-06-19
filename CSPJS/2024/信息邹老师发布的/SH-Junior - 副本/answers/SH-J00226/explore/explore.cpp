#include<iostream>
#include<cstring>
using namespace std;
string a[1002];
int n,m;
char check(int x,int y,int d)
{
	if (d==0) y++;
	else if (d==1) x++;
	else if (d==2) y--;
	else x--;
	if (x>=0 && y>=0 && x<=n-1 && y<=m-1) return a[x][y];
	else return 'x';
}
void move(int *x,int *y,int d)
{
	if (d==0)	++*y;
	else if (d==1) ++*x;
	else if (d==2) --*y;
	else --*x;
}
void turn(int *d)
{
	*d=(*d+1)%4;
 } 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t; cin>>t;
	while(t--)
	{
		bool vis[1002][1002]={0,};
		
		long long ans=1;
		int k; cin>>n>>m>>k;
		int x,y,d; cin>>x>>y>>d;
		x--; y--;
		vis[x][y]=1;
		for (int i=0;i<n;i++) cin>>a[i];
		while (k>0)
		{
			int t=check(x,y,d); 
			if (t=='.')
			{
				move(&x,&y,d);
				k--;
				if (!vis[x][y])
				{
					ans++;
					vis[x][y]=1;
				}
			}
			else
			{
				turn(&d);
				k--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
