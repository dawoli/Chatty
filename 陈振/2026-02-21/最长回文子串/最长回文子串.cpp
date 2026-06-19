#include <bits/stdc++.h>
#define dp(x,y) f[1000*(x)+(y)]
using namespace std;
typedef long long int ll;
string s;
bitset<10000001> f;
int n,ans=1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		dp(i,i)=1;
		if(i!=n-1)
		{
			if(s[i]==s[i+1])
			{
				dp(i,i+1)=1;
				ans=2;
			}
		}
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=0;i+l-1<n;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j]&&dp(i+1,j-1))
			{
				dp(i,j)=1;
				ans=max(ans,l);
			}
		}
	}
	cout<<ans;
	return 0;
}