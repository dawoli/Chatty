#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
struct node
{
	int x,y,d;
	void turn()
	{
		d=(d+1)%4;
	}
	void step()
	{
		x+=dx[d],y+=dy[d];
	}
	operator pair<int,int>()
	{
		return make_pair(x,y);
	}
};
using pii=pair<int,int>;
char a[1010][1010];
int n,m,k;
node nd;
void solve()
{
	set<pii> sp;
	cin>>n>>m>>k;
	cin>>nd.x>>nd.y>>nd.d;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	sp.insert(pii(nd));
	while (k--)
	{
		node nd1=nd;
		nd1.step();
		if (nd1.x<1||nd1.x>n||nd1.y<1||nd1.y>m||a[nd1.x][nd1.y]=='x')
		{
			nd.turn();
		}
		else
		{
			nd.step();
		}
		sp.insert(pii(nd));
	}
	cout<<sp.size()<<endl;
}
const string fileio="explore";
int main()
{
	freopen((fileio+".in").c_str(),"r",stdin);
	freopen((fileio+".out").c_str(),"w",stdout);
	int t;
	cin>>t;
	while (t--)solve();
}
