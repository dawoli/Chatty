#include <iostream>
#include <ciostd>
using namespace std;
int n,k,m,x,y,d;
int ks[100000];
char forest[10]{1005}{1005};
bool i={1005}{1005};
int dry[4][2]={0,1},{1,0},{0,-1},{-1,0};
int func()
{
	int ans=0;
	int ta=a+dry[cx{0}]	
	int tb=b+dry[cx{0}]	
	for(int i=1;i<=k;i++)
	{
		int tx=x+dry[4][0];
		int ty=y+dry[4][0];	
	}
	if(ix[ty][tx])
	{
		ans++;
		ix[tx][ty]=true;
		x=tx;
		y=ty;	
	}
	
	return ans;	
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j=1;j<=k;j++)
		{
			cin >> k[i];	
		}
		for(int l=1;l<=m;l++)
		{
			cin >> forest[j][l];	
		}	
	}
	cout << func()<< endl;
	return 0;
}
