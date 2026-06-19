#include<bits/stdc++.h>
using namespace std;

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

int n, q;
char s1[1000][2000];
char s2[1000][2000];
char t1[2000], t2[2000];
char t3[2000];
int ans;
bool p;
bool zh;

bool pan(int x, int y, int z)
{
	for(int i = 0; i < strlen(s1[x]); i++)
	{
		if(s1[x][y+i] != t1[z+i]) return 0;
	}
	return 1;
}

void huan(int x, int y, int z)
{
	for(int i = 0; i < strlen(s1[x]); i++)
	{
		t3[z+i] = s2[x][y+i];
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int w = 0; w < q; w++)
	{
		ans = 0;
		cin >> t1 >> t2;
		if(strlen(t1) != strlen(t2))
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			if(strlen(t1) < strlen(s1[i])) continue;
			for(int j = 0; j < strlen(t1); j++) t3[j] = t1[j];
			for(int j = 0; j < strlen(s1[i]); j++)
			{
				zh = 0;
				for(int k = 0; k < strlen(t1); k++)
				{
					if(s1[i][j] == t1[k])
					{
						if(pan(i, j, k))
						{
							huan(i, j, k);
							zh = 1;
							break;
						}
					}
					if(zh) break;
				}
				if(zh) break;
			}
			p = 1;
			if(strlen(t3) != strlen(t2)) p = 0;
			for(int h = 0; h <= strlen(t1); h++)
			{
				if(t2[h] != t3[h]) p = 0;
			}
			if(p == 1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
