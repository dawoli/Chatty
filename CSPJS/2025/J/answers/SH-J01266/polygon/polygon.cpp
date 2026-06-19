#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>> n;
	/**while(cin>>s)
	{
		//cout<<s;
		if(int(s)>=48&&int(s)<=57)
			a[int(s)-48]++;
	}*/
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int ans=0;
		if(a[1]+a[2]>a[3])ans++;
		if(a[3]+a[2]>a[1])ans++;
		if(a[1]+a[3]>a[2])ans++;
		cout<<ans;
		return 0;
	}
		
	/*for(int i=0;i<=s.length();++i)
	{
		//cout<<s[i];
		if(int(s[i])>=48&&int(s[i])<=57)
			a[int(s[i])-48]++;
	}	
	
	for(int i=9;i>=0;--i)
	{
		//cout<<a[i];
		for(long long j=1;j<=a[i];j++)
			cout<<i;
	}*/
	cout<<n*2;
	return 0;
}
