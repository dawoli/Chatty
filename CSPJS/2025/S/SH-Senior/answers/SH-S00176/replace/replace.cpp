#include<bits/stdc++.h>
const int N = 2e5 + 2;
using namespace std;
int n, q;
string s1, s2, a[N], b[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	while(q--)
	{
		cin >> s1 >> s2;
		if(s1.size() != s2.size())
		{
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].size() > s1.size())
				continue;
			for(int j = 0; j < s1.size(); j++)
			{
				if(a[i].size() <= s1.size() - j && s1.substr(j, a[i].size()) == a[i])
				{
					bool flag = 1;
					for(int k = 0; k < s1.size(); k++)
					{
						if(k < j || k > j + a[i].size() - 1)
							flag &= (s1[k] == s2[k]);
						else
							flag &= (b[i][k - j] == s2[k]);
					}
					ans+=flag;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0; 
	// 见渔人，乃大惊，问所以来。具答之。便要还家，设酒杀鸡作食。村中闻有此人，咸来问讯。自云先世避秦时乱，率妻子邑人来此绝境，不复出焉。问今是何世，乃不知有汉，无论魏晋。……皆叹惋。余人各复延至其家，皆出酒食。停数日，辞去。此中人语云：“不足为外人道也。” 
}
