#include <bits/stdc++.h>
using namespace std;

const int N=507;

string s1[N],s2[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	for (int i=1;i<=n;i++)
		cin >> s1[i] >> s2[i];
	while (q--)
	{
		int ans=0;
		string t1,t2;
		cin >> t1 >> t2;
		for (int i=1;i<=n;i++)
			for (int j=0;j+s1[i].size()<=t1.size();j++)
			{
				if (j>=1)
					if(t1.substr(0,j)!=t2.substr(0,j))
						continue;
				if (j+s1[i].size()<t1.size())
					if(t1.substr(j+s1[i].size(),t1.size()+s1[i].size()-j)!=t2.substr(j+s1[i].size(),t1.size()+s1[i].size()-j))
						continue;
				if (t1.substr(j,s1[i].size())!=s1[i])
					continue;
				if (t2.substr(j,s1[i].size())!=s2[i])
					continue;
				ans++;
			}
		cout << ans << endl;
		
	}
	return 0;
}
