#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("poker.in","r",stdin);
	freopen ("poker.out","w",stdout);
	int n,ans=0;
	cin >>n;
	char s[55][2];
	for (int i=0;i<n;++i)
	{
		cin >>s[i][0]>>s[i][1];
		for (int j=0;j<i;++j) if (s[i][0]==s[j][0]&&s[i][1]==s[j][1])
		{
			ans--;
			break;
		}
		ans++;
	}
	cout <<52-ans;
	return 0;
}
