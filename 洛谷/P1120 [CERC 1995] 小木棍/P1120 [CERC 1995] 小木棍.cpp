// Problem URL: https://www.luogu.com.cn/problem/P1120
// Finish Time: 2026/4/11 17:18:54 WA 57pts
// Finish Time: 2026/4/11 17:12:22 WA 54pts
// Finish Time: 2026/4/11 16:26:05 WA 33pts
// Finish Time: 2026/4/11 15:38:03 WA 20pts
// Start Time: 2026/4/11 12:26:33

#include <bits/stdc++.h>
using namespace std;
int n,a[66],fmn,mx=INT_MIN,sum=0,t,f=0;
bitset<66> vis;
bool check(int x,int l,int g,int c=1)
{
	if(l==g)c++,l=0,f=0,x=1;
	if(c>t)return true;
	for(int i=x;i<=n;i++)
	{
		if(vis[i]||l+a[i]>g||a[i]==f)continue;
		vis[i]=1;
		if(check(i+1,l+a[i],g,c))return true;
		vis[i]=0;
		f=a[i];
		if(sum==0||sum+a[i]==g)return false;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("P1120_3.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>50)i--,n--;
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=mx;i<=sum/2;i++)
	{
		if(sum%i!=0)continue;
		t=sum/i;
		if(check(1,0,i))
		{
			cout<<i;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}