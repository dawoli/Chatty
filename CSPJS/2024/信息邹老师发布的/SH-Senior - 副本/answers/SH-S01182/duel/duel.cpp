#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("duel.in","r",stdin);
	freopen ("duel.out","w",stdout);
	long long n,t,f=0,i;
	cin >>n;
	long long a[n];
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
