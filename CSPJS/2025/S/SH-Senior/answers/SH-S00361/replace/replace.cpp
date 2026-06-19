#include<bits/stdc++.h>
using namespace std;

string s[200010][3];
string t[200010][3];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)cin >> s[i][1] >> s[i][2];
	for(int i = 1;i <= q;i++)cin >> t[i][1] >> t[i][2];
	int l1 = 0,l2 = 0;
	for(int i = 1;i <= n;i++)l1 += s[i][1].size()+s[i][2].size();
	for(int i = 1;i <= q;i++)l2 += t[i][1].size()+t[i][2].size();
	if(l1 <= 2000 && l2 <= 2000)
	{
		unordered_map<string,int> mp;
		for(int i = 1;i <= n;i++)mp[s[i][1] + s[i][2]]++;
		for(int i = 1;i <= q;i++)
		{
			int ans = 0;
			if(t[i][1].size() != t[i][2].size())
			{
				cout << "0\n";
				continue;
			}
			int len = t[i][1].size();
			int pos1 = 0,pos2 = len - 1;
			while(t[i][1][pos1] == t[i][2][pos1])pos1++;
			while(t[i][1][pos2] == t[i][2][pos2])pos2--;
			for(int j = 0;j <= pos1;j++)
			{
				string a = t[i][1].substr(j,pos2 - j);
				string b = t[i][2].substr(j,pos2 - j);
				for(int k = pos2;k < len;k++)
				{
					a += t[i][1][k],b += t[i][2][k];
					ans += mp[a + b];
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
