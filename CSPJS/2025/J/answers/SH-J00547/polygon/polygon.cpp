#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";
	}
	else
	{
		int er=8,cha=7;
		for(int i=4;i<=n;i++)
		{
			er*=2;
			er%=998244353;
			cha+=i;
			cha%=998244353; 
		}
		cout<<(er-cha)%998244353;
	}
	return 0;
}
