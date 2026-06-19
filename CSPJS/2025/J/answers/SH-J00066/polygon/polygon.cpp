#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>;
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5000];
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	long long t=max(max(a[1],a[2]),a[0]);
	if(n==3 && a[0]+a[1]+a[2]>2*t)cout<<1;
	else cout<<0;
	return 0;
}
