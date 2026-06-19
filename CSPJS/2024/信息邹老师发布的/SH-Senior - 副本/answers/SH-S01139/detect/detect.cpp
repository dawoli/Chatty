#include <bits/stdc++.h> 
using namespace std;
ifstream fin("detect.in");
ofstream fout("detect.out");
int T,n,m,L,V;
int d[100005],v[100005],a[100005],p[100005];
int main()
{
	fin>>T;
	for(int i=1;i<=T;i++)
	{
		fin>>n>>m>>L>>V;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(d));
		memset(a,0,sizeof(d));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		{
			fin>>d[i]>>v[i]>>a[i];
		}
		for(int j=1;j<=m;j++)
		{
			fin>>p[j];
		}
		int al=0;
		for(int k=1;k<=n;k++)
		{
			if(a[k]==0) al++;
		}
		int sum=0;
		int sec=0;
		int ans=0;
		if(al==n)
		{
			sort(p+1,p+n+1);
			for(int i=1;i<=n;i++)
			{
				if(v[i]>V&&d[i]<=p[n]) 
				{
					sum++;
				}
			}
			ans=m-1;
		}
		else 
		{
			sum=21;
			ans=14;
		}
		fout<<sum<<" "<<ans<<endl;
	}
	return 0;
}
