#include <bits/stdc++.h>
using namespace std;
int n, Q;
string s1[200010], s2[200010];
string str1, str2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> Q;
	for(int i = 1;i <= n;i ++)
		cin >> s1[i] >> s2[i];
	
	while(Q --)
	{
		int ans = 0;
		bool fg = 1;
		cin >> str1 >> str2;
		for(int l = 0, r = str1.length() - 1;;)
		{
			if(l > r)
				break;
			string s = "", lft = "", rit = "";
			for(int i = l;i <= r;i ++)
				s += str1[i];
			for(int i = 0;i < l;i ++)
				lft += str1[i];
			for(int i = r + 1;i < str1.length();i ++)
				rit += str1[i];
			for(int i = 1;i <= n;i ++)
			{
				if(s1[i] == s)
					if(lft + s2[i] + rit == str2)
						ans ++;		
			}

			if(fg == 1)
				l ++, fg = 0;
			else
				r --, fg = 1;
		}
		
		cout << ans << endl;
	}
	return 0;
}
