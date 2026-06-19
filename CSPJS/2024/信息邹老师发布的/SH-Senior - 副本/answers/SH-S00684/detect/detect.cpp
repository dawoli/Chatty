#include <bits/stdc++.h>

using namespace std;
int d[1000010];
int a[1000010];
int v[1000010];
int sh[1000010];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	int ans=0;
	int n,m,L,V;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>sh[i];
		}
		for(int i=1;i<=n;i++)
		{
			int s=L-d[i];
			if(v[i]>v&&s==sh[i])
			{
				ans++;
			}
			
			v[i]+=a[i];
		}
	}
	cout<<ans<<L-v[2];

	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ©\2
6 4 ©\4
2 5 8 9 15
*/
