#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	int x=b[1],t=n*m;
	sort(b+1,b+t+1);
	for(int i=t;i>=1;i--)
	{
		a[t+1-i]=b[i];
		if(a[t+1-i]==x) x=t-i+1;
	}
	int ans=1;
	for(int i=1;x>n;i++) 
	{
		ans++;
		x-=n;
	}
	cout<<ans<<" ";
	if(ans%2==1)
	{
		if(x==0) cout<<n;
		else cout<<x;
	}
	else if(ans%2==0)
	{
		if(x==0) cout<<1;
		else cout<<n-x+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
