#include<bits/stdc++.h>
using namespace std;
long long T;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T>0)
	{
		int n,m,l,vlo;//A
		int d[100009],v[100009],a[100009],p[100009];
		long long pmv[100009];
		int ans=0;
		cin>>n>>m>>l>>vlo;
		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
		}
		//sort(p,p+m);
		for(int i=0;i<n;i++)
		{
			pmv[i]=v[i]*v[i]+2*a[i]*(p[m-1]-d[i]);
			if(d[i]<=p[m-1]&&pmv[i]>vlo*vlo)
				ans++;
		}
		cout<<ans<<' ';
		if(ans==0)
			cout<<m;
		else
			cout<<m-1;
		cout<<endl;
		T--;//A
	}
	return 0;
} 
