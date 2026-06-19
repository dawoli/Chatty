#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	int n,k,ans=0,cnt=0;
	cin>>n>>k;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(cnt==0)ans+=a[i];
		cnt++;
		if(cnt==k)cnt=0;
	}
	cout<<ans;
	return 0;
} 
