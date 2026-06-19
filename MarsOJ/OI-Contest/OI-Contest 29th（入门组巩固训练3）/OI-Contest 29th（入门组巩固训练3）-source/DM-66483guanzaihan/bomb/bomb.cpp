#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	for(int i = 1;i <= T;i++)
	{
		int n, m, ans= 0;
		string s;
		cin >> n >> m;
		cin >> s;
		for(int j = 0;j < s.size();j++)
		{
			if(s[j]=='$')
				ans++;
		}
		cout << ans << " " << s.size()-1;
	}
	return 0;
}
