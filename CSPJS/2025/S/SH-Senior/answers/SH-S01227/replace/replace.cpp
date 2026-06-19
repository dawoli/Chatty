#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 8;
int n, pppq;
struct node
{
	char pre, nxt;
	int tto, fail, thedepth, haven;
}tree[MAXN];
inline int read (char *target)
{
	char t;
	t = getchar();
	while (t < 'a' || t > 'z') t = getchar();
	
	int dt = 0;
	while ('a' <= t && t <= 'z')
	{
		*(target + dt) = t;
		dt++;
		t = getchar();
	}
	return dt;
}
char a[MAXN];
char b[MAXN];
vector <int> sons[MAXN];
int ddontree = 1;
void build (int root, int len, int depth)
{
	if (depth > len)
	{
		tree[root].haven = 1;
		return;
	}
	bool flag = 1;
	for (int p : sons[root])
	{
		if (tree[p].pre == a[depth] && tree[p].nxt == b[depth])
		{
			build (tree[p].tto, len, depth + 1);
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		ddontree++;
		tree[ddontree] = (node){a[depth], b[depth], ddontree, 0, depth};
		sons[root].push_back(ddontree);
		//cout << "addpoint: num=" << ddontree << "  pre=" << a[depth] << "  nxt=" << b[depth] << " father=" << root << endl;
		build (ddontree, len, depth + 1);
	}
}
int childt[26 * 26 + 1];
void build_fail (int root)
{
	if (root == 1)
	{
		for (int p : sons[root])
		{
			tree[p].fail = 1;
			//cout << "fail of " << p << " is " << 1 << endl;
			build_fail(p);
		}
	}
	else
	{
		for (int p : sons[root])
		{
			bool flag = 0;
			for (int q : sons[tree[root].fail])
			{
				if (tree[q].pre == tree[p].pre && tree[q].nxt == tree[p].nxt)
				{
					tree[p].fail = q;
					//cout << "fail of " << p << " is " << q << endl;
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				if (childt[(tree[p].pre - 'a') * 26 + (tree[p].nxt - 'a')] != 0)
				{
					tree[p].fail = childt[(tree[p].pre - 'a') * 26 + (tree[p].nxt - 'a')];
					//cout << "fail of " << p << " is " << childt[(tree[p].pre - 'a') * 26 + (tree[p].nxt - 'a')] << endl;
				}
				else
				{
					tree[p].fail = 1;
					//cout << "fail of " << p << " is " << 1 << endl;
				}
			}
			build_fail(p);
		}
	}
	return;
}
char inpre[MAXN], innxt[MAXN];
string blpre[MAXN], blnxt[MAXN];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> pppq;
	if (n <= 200)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> blpre[i] >> blnxt[i];
		}
		while (pppq--)
		{
			string bla, blb;
			cin >> bla >> blb;
			int ans = 0;
			if (bla.length() != blb.length())
			{
				cout << 0 << endl;
				continue;
			}
			int len = bla.length();
			int line = len - 1;
			while (bla[line] == blb[line]) line--;
			int stline = 0;
			while (bla[stline] == blb[stline]) stline++;
			for (int i = 0; i <= stline; i++)
			{
				for (int k = 1; k <= n; k++)
				{
					int lenbl = blpre[k].length();
					bool flag = 1;
					for (int j = 0; j < lenbl; j++)
					{
						if (i + j >= len)
						{
							flag = 0;
							break;
						}
						if (blpre[k][j] != bla[i + j] || blnxt[k][j] != blb[i + j])
						{
							flag = 0;
							break;
						}
					}
					if (flag && i + lenbl - 1 >= line)
					{
						ans++;
					}
				}	
			}
			cout << ans << endl;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int lena = read(a + 1);
		int lenb = read(b + 1);
		build (1, lena, 1);
	}
	for (int p : sons[1])
	{
		childt[(tree[p].pre - 'a') * 26 + (tree[p].nxt - 'a')] = tree[p].tto;
	}
	build_fail(1);
	while (pppq--)
	{
		int ans = 0;
		int lena = read(inpre + 1);
		int lenb = read(innxt + 1);
		if (lena != lenb)
		{
			cout << 0 << endl;
			continue;
		}
		int len = lena;
		int line = len;
		while (inpre[line] == innxt[line]) line--;
		int stline = 1;
		while (inpre[stline] == innxt[stline]) stline++;
		int curdt = 1;
		int destontree = 1;
		int startpos = 1;
		while (stline >= startpos)
		{
			bool flag = 0;
			while (!flag)
			{
			//	cout << "check " << curdt << " on " << destontree << endl;
				for (int p : sons[destontree])
				{
					if (tree[p].pre == inpre[curdt] && tree[p].nxt == innxt[curdt])
					{
						destontree = p;
						//cout << "find!" << endl;
						flag = 1;
						break;
					}
				}
				if (flag) break;
				if (!flag && destontree == 1)
				{
					startpos = curdt + 1;
					break;
				}
				if (!flag) 
				{
					destontree = tree[destontree].fail;
					startpos = curdt - tree[destontree].thedepth;
				}
				//cout << "fail!" << endl;
			}
			if (tree[destontree].haven == 1 && curdt >= line && stline >= startpos)
			{
				//cout << "findans! :" << startpos << " " << curdt << endl;
				ans++;
				destontree = 1, startpos++, curdt = startpos;
				continue;
			}
			curdt++;
		}
		cout << ans << endl;
	}
	return 0;
}
/**

5 2
xabcx xadex
ab cd
bc de
aa bb
ac bb
xabcx xadex
aaaa bbbb

**/
