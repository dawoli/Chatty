#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long hash_type;
const int N = 2e5+9;
const int L = 5e6+9;
const hash_type B = 13331;
int n,q,len[N];
hash_type p[L],th1[L],th2[L],sh1[N],sh2[N];
char s[L],t1[L],t2[L];
inline hash_type hsh1(const int&l, const int&r) {return th1[r] - th1[l - 1] * p[r - l + 1];}
inline hash_type hsh2(const int&l, const int&r) {return th2[r] - th2[l - 1] * p[r - l + 1];}
map<int, vector<int> > mp;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	bool isB = 1;
	scanf("%d%d", &n, &q);
	p[0] = 1;
	for (int i = 1; i < L; ++i) p[i] = p[i - 1] * B;
	for (int i = 1; i <= n; ++i)
	{
		scanf(" %s", &s[1]);
		len[i] = strlen(&s[1]);
		sh1[i] = 0;
		for (int j = 1; j <= len[i]; ++j) (sh1[i] *= B) += s[j];
		// int nA = 0,nB = 0,pB = -1;
		// for (int j = 1; j <= len[i]; ++j) if (s[j] == 'a') ++nA; else if (s[j] == 'b') ++nB,pB = j;
		// if (nB != 1 || nA != len[i] - 1) isB = 0;
		scanf(" %s", &s[1]);
		sh2[i] = 0;
		for (int j = 1; j <= len[i]; ++j) (sh2[i] *= B) += s[j];
		// nA = nB = 0;
		// int pB2 = -1;
		// for (int j = 1; j <= len[i]; ++j) if (s[j] == 'a') ++nA; else if (s[j] == 'b') ++nB,pB2 = j;
		// if (nB != 1 || nA != len[i] - 1) isB = 0;
		// if (isB) mp[pB - pB2].push_back(len[i]);
	}
	// if (isB) for (auto&it : mp) sort(it.second.begin(), it.second.end());
	while (q--)
	{
		scanf(" %s %s", &t1[1], &t2[1]);
		int l = strlen(&t1[1]);
		if (l != strlen(&t2[1]))
		{
			puts("0");
			continue;
		}
		// if (isB)
		// {
		// 	int nA1 = 0,nB1 = 0,nA2 = 0,nB2 = 0,pB1 = -1,pB2 = -1;
		// 	for (int i = 1; i <= l; ++i) if (t1[i] == 'a') ++nA1; else if (t1[i] == 'b') ++nB1,pB1 = i;
		// 	for (int i = 1; i <= l; ++i) if (t2[i] == 'a') ++nA2; else if (t2[i] == 'b') ++nB2,pB2 = i;
		// 	if (nA1 == l - 1 && nA2 == l - 1 && nB1 == 1 && nB2 == 1)
		// 	{
		// 		if (!mp.count(pB1 - pB2)) puts("0");
		// 		else
		// 		{
		// 			vector<int> vec = mp[pB1 - pB2];
		// 			printf("%d\n", upper_bound(vec.begin(), vec.end(), l) - vec.begin());
		// 		}
		// 		continue;
		// 	}
		// }
		for (int i = 1; i <= l; ++i) th1[i] = th1[i - 1] * B + t1[i];
		for (int i = 1; i <= l; ++i) th2[i] = th2[i - 1] * B + t2[i];
		int ans = 0;
		for (int i = 1; i <= n; ++i) for (int x = 1; x + len[i] - 1 <= l; ++x) if (hsh1(1, x - 1) == hsh2(1, x - 1)
			&& hsh1(x + len[i], l) == hsh2(x + len[i], l) && hsh1(x, x + len[i] - 1) == sh1[i] && hsh2(x, x + len[i] - 1) == sh2[i]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}