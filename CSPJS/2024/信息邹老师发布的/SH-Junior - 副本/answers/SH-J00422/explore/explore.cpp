#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[1009][1009];
int main()
{
	freopen("explore.in","w",stdin);
	freopen("explore.out","r",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		set<pair<int,int>> s;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)cin>>c[i][j];
		s.insert(make_pair(x,y));
		for(int i=1;i<=k;i++)
		{
			if(x+dx[d]<1||x+dx[d]>n||y+dy[d]<1||y+dy[d]>m||c[x+dx[d]][y+dy[d]]=='x')d=(d+1)%4,cout<<d<<endl;
			else x+=dx[d],y+=dy[d],s.insert(make_pair(x,y));
		} 
		cout<<s.size()<<endl;
	}
	return 0; 
}
