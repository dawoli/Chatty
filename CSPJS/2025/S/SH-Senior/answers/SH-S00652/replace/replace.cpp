#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j < t1.size() - s1[i].size();j++)
			{
				if(t1[j] == s1[i][0])
				{
					bool f = 1;
					for(int k = 1;k < s1[i].size();k++)
					{
						if(s1[i][k] != t1[j + k])
						{
							f = 0;
							break;
						}
					}
					if(f)
					{
						bool v = 1;
//						string s3 = t1.substr(0,j),s4 = t1.substr(j + s1[i].size());
//						string s5 = s3 + s2[i] + s4;
//						if(s5 == t2)
//							ans++;
						for(int k = 1;k < s2[i].size();k++)
						{
							if(t2[j + k] != s2[i][k])
							{
								v = 0;
								break;
							}
						}
						if(v)
							ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
