// Problem URL:  
// Finish Time: 2026/4/11 18:08:39 AC
// Finish Time: 2026/4/11 18:03:31 WA
// Start Time: 2026/4/11 17:37:17

#include<bits/stdc++.h>
#define maxn 101
using namespace std;
int n,f[maxn];
int work(int n)
{
	if(n==0||n==1)return f[n];
	if(f[n]!=-1)return f[n];
	int ans=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,2*work(n-i)+(int)pow(2.0,i*1.0)-1);
	}
	f[n]=ans;
	return f[n];
}
int main()
{
	cin>>n;
	memset(f,-1,sizeof(f));
	f[0]=0,f[1]=1;
	cout<<work(n);
	return 0;
}