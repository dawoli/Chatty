#include <iostream>
using namespace std;

int n, q, cnt;
string s1, s2, rep1[200010], rep2[200010], temp;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> rep1[i] >> rep2[i];
	}
	while (q--)
	{
		cnt = 0;
		cin >> s1 >> s2;
		for (int i = 1; i <= n; i++)
		{
			while (s1.find(rep1[i]) != string::npos)
			{
				temp = s1;
				s1.replace(s1.find(rep1[i]), rep1[i].size(), rep2[i]);
				if (s1 == s2)
				{
					cnt++;
				}
				s1 = temp;
			}
		}
	}//ºÃÄÑ°¡·ÅÆú°É¡£ 
	return 0;
}
