#include<bits/stdc++.h>
using namespace std;
bool cmp(int m,int n)
{
	return m>n;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=1,same=0; 
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])same++;
		else same=0;
		
		if(ans<=same)
		ans++;
		
	}
	cout<<ans;
	return 0;
 } 
