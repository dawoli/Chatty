#include<bits/stdc++.h>
using namespace std;
int a[7];
int t,n,m;
string s;
int ans=0;
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		memset(a,0,sizeof(a));
		ans=0;
		for(int i=1;i<=5;i++)
			for(int j=1;j<=8;j++)
			{
				cin>>s;
				if(s=="math")
					a[i]++,ans++;
			}
		cin>>n>>m;
		ans=ans*(n/7);
		for(int i=1;i<=n%7;i++)
			ans+=a[i];
		for(int i=1;i<m;i++)
			ans+=a[(i+n%7)%7]-a[i];
		cout<<ans<<endl;
	}
	return 0;
} 
