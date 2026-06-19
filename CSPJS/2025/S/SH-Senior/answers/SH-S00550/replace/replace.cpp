#include <bits/stdc++.h>
using namespace std;
string s[105][3];
unsigned long long val1[105], val2[105];
int lll[105];
bool f[105];
int lt[105], rt[105];
unsigned long long H1(int p, int l, int r)
{
	unsigned long long res = 0;
	for (int i = l; i <= r; i++)
	{
		res = res*13331+s[p][1][i]-'a'+1;
	}
	return res;
}
unsigned long long H2(int p, int l, int r)
{
	unsigned long long res = 0;
	for (int i = l; i <= r; i++)
	{
		res = res*13331+s[p][2][i]-'a'+1;
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool spec_b = 0;
	int n, q;
	cin >> n >> q;
	if (n < 100)
	{
		memset(f,0,sizeof(f));
		int sc = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i][1] >> s[i][2];
			int l = 2147483647, r = -1;
			for (int j = 0; j < s[i][1].size(); j++)
			{
				if (s[i][1][j] != s[i][2][j])
				{
					l=min(l,j);
					r=max(r,j);
				}
			}//cout << i << ' ' << l << ' ' << r << '\n';
			if (l == 2147483647) 
			{
				f[i] = 1;
				sc++;
			}
			else
			{
				lt[i]=l;
				rt[i]=s[i][1].size()-r-1;
				lll[i] = r+1;
				val1[i] = H1(i,l,r);
				val2[i] = H2(i,l,r);
			}
		}
		for (int i = 1; i <= q; i++)
		{
			int rans = 0;
			int l = 2147483647, r = -1;
			cin >> s[n+1][1] >> s[n+1][2];
			//char* yy = s[n+1][1];
			for (int j = 0; j < s[n+1][1].size(); j++)
			{
				if (s[n+1][1][j] != s[n+1][2][j])
				{
					l=min(l,j);
					r=max(r,j);
				}
			}	
			if (l == 2147483647) 
			{
				cout << sc << '\n';
				continue;
			}
			int v1 = H1(n+1,l,r);
			int v2 = H2(n+1,l,r);
			for (int j = 1; j <= n; j++)
			{
				if (val1[j] == v1 && val2[j] == v2)
				{
					bool fl = 1;
					int oo = -1;
					if (l-lt[j]+1 < 1 || r+rt[j] > s[n+1][1].size())
					{
						fl = 0;
					}
					else
					{
						for (int o = l-lt[j]; o <= l-1; o++)
						{
							oo++;
							if (s[n+1][1][o] != s[j][1][oo])
							{
								//cout << oo << ' ' << s[n+1][1][o] << ' ' << s[j][1][oo] << '\n';
								//cout << j << "boo\n";
								fl = 0;
								break;
							}
						}
						oo = lll[j];
						//cout << rt[j] << "rt\n";
						for (int o = r+1; o <= r+rt[j]; o++)	
						{
							if (s[n+1][2][o] != s[j][2][oo])
							{
								//cout << oo << ' ' << s[n+1][2][o] << ' ' << s[j][2][oo] << '\n';
								//cout << j << "boo\n";
								fl = 0;
								break;
							}	
							oo++;
						}						
					}
					if (fl)
					{
						
						rans++;
					}
				}
			}
			cout << rans << '\n';
		}
		//return 0;
	}
//	int mov[]
//	for (int i = 1; i <= n; i++)
//	{
//		string a, b;
//		cin >> a >> b;
//		int lt = a.size();
//		for (int j = 1; j <= lt; j++)
//		{
//			
//		}
//	}
	return 0;
}
