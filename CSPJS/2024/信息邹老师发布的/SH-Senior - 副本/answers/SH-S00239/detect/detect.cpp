#include<bits/stdc++.h>
using namespace std;
int T;
int d[100000],w[100000],a[100000];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=0;i<n;i++)
		{
			for(int i=0;i<n;i++)
			{
				cin>>d[i]>>w[i]>>a[i];
			}
			int x=0;
			for(int i=0;i<m;i++)
			{
				int temp;
				cin>>temp;
				if(temp>x&&temp<=l)
				{
					x=temp;
				}
			}
			int res=0;
			for(int i=0;i<n;i++)
			{
				int s=x-d[i];
				double spd=pow(1.0*pow(w[i],2)+1.0*2*a[i]*s,0.5)
				if(spd>v&&d[i]<x)
				{
					res++;
				}
			}
		}
		cout<<res<<" "<<m-1<<endl;
	}
}
