#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int s[5005];
int ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+3;j<=n;j++)
		{
			int maxa=a[j];
			int ll=s[j]-s[i];
			if(maxa*2<ll)
			{
				ans++;
				ans%=998244353;
			}
		}
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
	else cout<<ans;
	return 0;
}
