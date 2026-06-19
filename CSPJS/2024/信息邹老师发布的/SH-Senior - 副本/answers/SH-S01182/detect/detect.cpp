#include <bits/stdc++.h>
using namespace std;
struct ha
{
	int d,v,a,q;
};
int main()
{
	freopen ("detect.in","r",stdin);
	freopen ("detect.out","w",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		int n,m,l,v,ans=0;
		cin >>n>>m>>l>>v;
		ha a[n];int p[m][2];
		for (int j=0;j<n;++j) cin >>a[j].a>>a[j].d>>a[j].v;
		for (int j=0;j<m;++j) cin >>p[j][0];
		for (int j=0;j<m;++j)
		{
			f=0;
			for (k=0;k<n;++k) if (d<sqrt(a[k].d*a[k].d+2*a[k].v*p[j][0]) p[m][1]=-1;
		}
		for (int j=0;j<m;++j) if (p[j][1]==-1) ans++;
		cout <<ans-3;
	}
	return 0;
}
