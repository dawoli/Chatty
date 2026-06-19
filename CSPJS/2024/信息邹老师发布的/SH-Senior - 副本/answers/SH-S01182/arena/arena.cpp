#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("arena.in","r",stdin);
	freopen ("arena.out","w",stdout);
	int n,t,f=0,i;
	cin >>n;
	int a[n];
	for (i=0;i<n;++i) cin >>a[i];
	for (i=0;i<n;++i) for (int j=0;j<i;++j) if (a[i]<a[j])
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	for (i=1;i<n;++i) if (a[f]<a[i]) a[++f]=-1;
	cout <<n-f;
	return 0;
}
