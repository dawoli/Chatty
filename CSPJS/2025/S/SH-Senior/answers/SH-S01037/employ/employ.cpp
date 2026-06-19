#include<bits/stdc++.h>
using namespace std;
long long n,m,d[100005],s,sum,B;
bool c[100005],A;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]==0)
		{
			s++;
			A=1;
			B++;
		}
	}
		for(int i=n;i>=1;i++)
		{
			sum*=n;
			sum%=998244353;
		}
		cout<<sum;
	return 0;
}
