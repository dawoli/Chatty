#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
struct person{
	int l;
	vector<int> a;
};
person x[100005];
int r[100005];
int c[100005]; 
bool ansans[10][100005];
//bool f[200005][200005];
vector<int> f[200005];
bool ff;
void dfs(int kk,int xx,int end)
{
	if(kk==0)
	{
		if(xx==end)
		{
			ff=1;
		}
		return;
	}
	for(int i=0;i<f[xx].size();i++)
	{
		dfs(kk-1,f[xx][i],end);
		if(ff==1)
		{
			break;
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int iii=1;iii<=T;iii++)
	{
		cin>>n>>k>>q;
		ansans[iii][0]=q;
		//cout<<"*  "<<iii<<" "<<0<<" "<<q<<endl;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j].l;
			for(int ii=1;ii<=x[j].l;ii++)
			{
				int t;
				cin>>t;
				x[j].a.push_back(t);
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<x[i].a.size();j++)
			{
				for(int ii=2;ii<=k and j+ii<x[i].l;ii++)
				{
					f[x[i].a[j]].push_back(x[i].a[j+ii]);
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			ff=0;
			dfs(r[i],1,c[i]);
			if(ff==1)
			{
				ansans[iii][i]=1;
				//cout<<"#  "<<i<<endl;
			}
		}
	}
	for(int i=1;i<=T;i++)
	{
		//cout<<"&  "<<i<<" "<<ansans[i][0];
		for(int j=1;j<=7;j++)
		{
			cout<<ansans[i][j]<<endl;
		}
	}
	return 0;
}
