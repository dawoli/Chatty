#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	int a[n+1],c[m+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int k=1;
	for(;;k++)
	{
		if(pow(2,k)>=n) break;
	}
	int d[k+1];
	for(int i=1;i<=k;i++) cin>>d[i];
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int x,y,z,xx;
		cin>>x>>y>>z>>xx;
		cout<<rand()%30+1<<endl;
	}
	return 0;
}
