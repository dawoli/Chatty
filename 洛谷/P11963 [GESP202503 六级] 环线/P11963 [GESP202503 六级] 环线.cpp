// Problem URL: https://www.luogu.com.cn/problem/P11963
// Finish Time: 2026/2/27 12:34:02 AC
// Finish Time: 2026/2/27 12:28:45 WA
// Finish Time: 2026/2/27 11:16:11 TLE 40pts 
// Start Time: 2026/2/27 10:44:22

// Categories: 动态规划
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,a[200001];
ll mx,mn,sum=0,cir,fmx,fmn;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	mx=fmx=mn=fmn=a[1];
	for(int i=2;i<=n;i++)
	{
		mx=max((ll)a[i],a[i]+mx);
		fmx=max(fmx,mx);
		mn=min((ll)a[i],a[i]+mn);
		fmn=min(fmn,mn);
	}
	cir=sum-fmn;
	if(cir==0) cout<<fmx;
	else cout<<max(fmx,cir);
	return 0;
}