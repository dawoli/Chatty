// Problem URL: https://www.luogu.com.cn/problem/T766543?contestId=330334
// Start Time: 2026/6/21 16:25:07

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int l=0,r=n-1;
	string ans;
	ans.reserve(n);
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			if(s[l]<s[r])
			{
				ans.push_back(s[l++]);
			}
			else
			{
				ans.push_back(s[r--]);
			}
		}
		else
		{
			char c=s[l];
			int i=l;
			while(i<=r&&s[i]==c) ++i;
			int a=i-l;
			char x=(i<=r)?s[i]:0;
			int j=r;
			while(j>=l&&s[j]==c) --j;
			int b=r-j;
			char y=(j>=l)?s[j]:0;
			if(i>r)
			{
				int len=r-l+1;
				int k=(len-1)/2;
				ans.append(len-k,c);
				break;
			}
			if(x<c&&y<c)
			{
				int k=min(a,b);
				ans.append(k,c);
				l+=k;
				r-=k;
			}
			else if(x < c&&y > c)
			{
				ans.append(a,c);
				l+=a;
			}
			else if(x>c&&y<c)
			{
				ans.append(b,c);
				r-=b;
			}
			else
			{
				ans.append(a+b,c);
				l+=a;
				r-=b;
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}