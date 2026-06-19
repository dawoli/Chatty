#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
int T,n,a[N][5],maxv;
vector<int> m[5];
void Main()
{
	cin>>n;
	int ans=0;
	for (int i=1;i<=3;i++)
	{
		m[i].clear();
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int &i1=a[i][1],&i2=a[i][2],&i3=a[i][3];
		int x,y;
		if (i1>=i2&&i1>=i3)
		{
			x=1;
			if (i2>=i3)y=2;
			else y=3;
		}
		else if (i2>=i1&&i2>=i3)
		{
			x=2;
			if (i1>=i3)y=1;
			else y=3;
		}
		else
		{
			x=3;
			if (i1>=i2)y=1;
			else y=2;
		}
		ans+=a[i][x];
		m[x].push_back(a[i][x]-a[i][y]);
	}
	if ((maxv=max({m[1].size(),m[2].size(),m[3].size()}))<=(n/2))
	{
		cout<<ans<<'\n';
		return;
	}
	int x,y;
	const int i1=m[1].size(),i2=m[2].size(),i3=m[3].size();
	if (i1>=i2&&i1>=i3)
	{
		x=1;
		if (i2>=i3)y=2;
		else y=3;
	}
	else if (i2>=i1&&i2>=i3)
	{
		x=2;
		if (i1>=i3)y=1;
		else y=3;
	}
	else
	{
		x=3;
		if (i1>=i2)y=1;
		else y=2;
	}
	sort(m[x].begin(),m[x].end());
	for (int i=0;i<m[x].size()-(n/2);i++)
	{
		ans-=m[x][i];
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while (T--)
	{
		Main();
	}
	return 0;
}
/*
void Prim()
{
	vector<int> vec;
	int n,m;
	cin>>n>>m;
	vec.resize(n);
	for (int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	int ans=0;
	for (int i=0;i<m;i++)
	{
		ans+=vec[i];
	}
	cout<<ans<<vec[m-1];
}
*/