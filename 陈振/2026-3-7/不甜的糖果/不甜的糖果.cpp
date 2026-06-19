// Problem URL:  
// Finish Time: 2026/3/7 17:30:54 AC
// Start Time: 2026/3/7 17:18:22

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=25*1e4+1;
int n,m,s[maxn],l=1,r,ans;
int sum(int start,int end)
{
	return s[end]-s[start-1];
}
int check(int x)
{
	for(int i=1;i+x-1<=n;i++)
		if(sum(i,i+x-1)>=m)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]+=s[i-1];
	}
	if(s[n]<m)
	{
		cout<<-1;
		return 0;
	}
	r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
/*
10 15
5 1 3 5 10 7 4 9 2 8
*/