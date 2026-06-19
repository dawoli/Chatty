#include<bits/stdc++.h>
using namespace std;
long long  n,a[500000],ans=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		ans*=2;
	}
	 cout<<ans-n(n-1)/2-n<<endl;
	
	return 0;
 } 
