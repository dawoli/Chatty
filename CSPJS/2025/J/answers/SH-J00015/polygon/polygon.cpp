#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(n==3)
	{
		int ans=0;
		if((a[1]+a[2]+a[3])>a[1]*2)ans++;
		cout<<ans;
		return 0;
	}
	int cnt=0;
	for(int i=3;i<=n;i++)
	{
		cnt+=(n-i)*n;
		cnt=cnt%998;
		cnt=cnt%244;
		cnt=cnt%353;
	}
	cnt+=1;
	cnt=cnt%998;
	cnt=cnt%244;
	cnt=cnt%353;
	cout<<cnt;
	return 0;

	
	
	

	fclose(stdin);
	fclose(stdout);
}
