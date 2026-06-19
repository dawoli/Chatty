#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,a[N],c[N];
vector<int> res[20];
string g[20];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
//		cout<<"OK";
	for(int i=1;i<=m;++i)
		cin>>c[i];
//		cout<<"OK";
	for(int i=1;i<=ceil(log2(n));++i)
		cin>>g[i];
	int t,x[4];
	cin>>t;
	while(t--)
	{
		for(int i=0;i<20;++i) res[i].clear();
		int sum=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=m;++i)
		{
			int k=log2(c[i]);
			for(int j=1;j<=c[i];++j) res[0].push_back(j);
//			cout<<'\n';
			for(int r=1;r<=k;++r)
			{
				for(int j=0;j<(1<<(k-r));++j)
				{
//			cout<<i;
					int id=res[r-1][j*2+g[r][j]-'0'];
					res[r].push_back(a[id]^x[id&3]>=r?id:(id&1?id+1:id-1));
//					cout<<res[r][j];
				}
//				cout<<'\n';
			}
			sum^=i*res[k][0];
		}
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
