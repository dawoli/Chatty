#include <bits/stdc++.h>
using namespace std;
long long t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
long long find(long long m,long long q,long long s)
{
	if (m==0)
		return s;
	long long minn=1e18;
	for (int i=0;i<10;i++)
	{
		if (q==0&&i==0)
		{
			q=1;
			continue;
		}
		if (m-a[i]>=0)
			minn=min(find(m-a[i],q,s=s*10+i),minn);
	}
	return minn;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		if (n<2)
			cout<<-1<<endl;
		else
			cout<<find(n,0,0)<<endl;
	}
 } 
