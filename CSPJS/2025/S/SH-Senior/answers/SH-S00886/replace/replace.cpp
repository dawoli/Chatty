#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,q;
string s[200005][3];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> t1 >> t2;
		int id1,id2;
		for (int j = 0;j < t1.size();j++)
		{
			if (t1[j] == 'b') id1 = j;
			if (t2[j] == 'b') id2 = j;
		}
		int cnt = 0;
		int id3,id4;
		for (int j = 1;j <= n;j++)
		{
			for (int k = 0;k < s[j][1].size();k++)
			{
				if (s[j][1][k] == 'b') id3 = k;
				if (s[j][2][k] == 'b') id4 = k;
			}
			if ((id1<id2 && id1>=id3 && (t1.size()-id1)>=(s[j][1].size()-id3)) || (id1>id2 && id2>=id4 && (t1.size()-id2)>=(s[j][1].size()-id4)))
			{
				if (id1-id2 == id3-id4) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
