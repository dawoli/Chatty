#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,V;
int q[1000000],d[1000000],v[1000000],a[1000000],p[1000000],f[1000000];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int c=0,clo=0;
		cin >>n>>m>>l>>V;
		for(int j=1;j<=n;j++) cin>>d[j]>>v[j]>>a[j];
		for(int k=1;k<=m;k++) cin>>p[k];
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
			{
				if(p[k]>=d[j])
				{
					int vv=v[j]*v[j]+2*a[j]*(p[k]-d[j]);
//					double dd=(V*V-v[j]*v[j])/(2*a[j]);
//					if(dd+d[j]>l)
//					{
//						f[j]=0;
//						break;
//					}
					if(vv>(V*V))
					{
						f[j]=1;	
						break;					
					}
					else q[j]=k;
					
					if(vv==0)
					{
						f[j]=0;
						break;
					}
									
				}
			}
		for(int j=1;j<=n;j++)
		{
			if(f[j]!=0) c++;
			if(q[j]!=0) clo++;
		}
		cout << c << ' ' << clo << endl;
	}
	return 0;
}
