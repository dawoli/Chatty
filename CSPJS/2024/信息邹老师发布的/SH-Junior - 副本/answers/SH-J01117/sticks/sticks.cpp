#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int t;
long long maxx;
int check(int m)
{
	int c[11]={6,2,5,5,4,5,6,3,7,6};
	long long sum=0;
	while(m>0)
	{
		sum+=c[m%10];
		m/=10;
	}
	return sum;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> b[i];
		maxx=max(maxx,b[i]);
	}
	for(int i=1;i<=500000000000000000000000;i++)
	{
		long long l=check(i);
		if(a[l]==0)
			a[l]=i;
		if(a[maxx]!=0)
			break;
	}
	for(int i=1;i<=t;i++)
	{
		if(a[b[i]]==0)
			cout << -1 << endl;
		else
			cout << a[b[i]] << endl;;
	}
	return 0;
 } 
