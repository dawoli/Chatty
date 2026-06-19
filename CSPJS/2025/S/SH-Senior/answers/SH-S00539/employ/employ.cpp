#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	char a;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='0')
		{
			cout<<"0";
			return 0;
		}
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	
	return 0;
}
