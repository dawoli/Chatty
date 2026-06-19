#include <bits/stdc++.h>
using namespace std;
struct node{int d , v , a;};
node u[100005];
int t;
int n , m , L , V;
int sp[100005];
void solve1()
{
	int cnt = 0;
	int cntt = 0;
	for(int i = 1 ; i<=n ; i++)
	{
		if(u[i].v > V) cnt++;
	}
	cout<<cnt<<" "<<m-1<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	bool fg = 1;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		for(int i = 1 ; i<=n ; i++)
		{
			cin>>u[i].d>>u[i].v>>u[i].a;
		}
		for(int i = 1 ; i<=m ; i++) cin>>sp[i];
		for(int i = 1 ; i<=n ; i++)
		{
			if(u[i].a != 0) fg = 0;
		}
		if(fg == 1) solve1();
	}
	return 0;
}
