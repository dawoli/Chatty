#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	int x,y,z;
};
node a[1000005];
vector<int>l[10005];
int f[100005],c[15][100005];
int tot=0;
bool cmp(node x,node y)
{
	return x.z<y.z; 
}
int find(int x)
{
	if (f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		l[x].push_back(y);
		l[y].push_back(x);
		a[i].x=x;
		a[i].y=y;
		a[i].z=z;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n+1;j++)
		{
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	int ans=0,cnt=0;
	for (int i=1;i<=m;i++)
	{
		if (cnt==n-1) break;
		int x=a[i].x,y=a[i].y;
		int fx=find(x),fy=find(y);
//		cout<<endl;
//		cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<endl;
		if (fx!=fy)
		{
			cnt++;
			f[fx]=fy;
			ans+=a[i].z;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 0
1 2 10
2 3 1
2 4 2
3 4 3

*/
