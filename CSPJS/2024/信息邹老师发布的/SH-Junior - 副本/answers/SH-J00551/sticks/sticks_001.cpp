#include<bits/stdc++.h>
#define int long long
using namespace std;
int ms[10]={6,2,5,5,4,5,6,3,7,6};
int g(int i)
{
	int sum=0;
	while(i!=0)
	{
		sum+=ms[i%10];
		i/=10;
	}
	return sum;
}
int pd(int n)
{
	if(n<=1)
		return -1;
	int i=0;
	while(g(i)!=n)
	{
		i++;
	}
	return i;
}
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		if(n>=100)
		{
			cout<<n-1/7<<endl;
			continue;
		}
		cout<<pd(n)<<endl;
	}
}
