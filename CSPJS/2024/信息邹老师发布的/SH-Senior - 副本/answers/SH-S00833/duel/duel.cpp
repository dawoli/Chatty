#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,s[maxn],ans;
int a[maxn],dp[maxn];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	int cnt=0,f=s[0];
	for(int i=0;i<n;i++)
	{
		if(s[i]==f)
		{
			dp[cnt]++;
		}else
		{
			f=s[i];
			cnt++;
			dp[cnt]++;
		}
	}
	for(int i=0;i<=cnt;i++)
	{
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;	
} 
/*10
136 136 136 2417 136 136 2417 136 136 136
*/

