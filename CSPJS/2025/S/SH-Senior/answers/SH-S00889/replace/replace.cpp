#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc getchar()
#define pc putchar
#define pii pair<int,int>
int read()
{
	int p = 1,x = 0;
	char c = gc;
	while(c < '0' || c > '9')	p == c == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
template<typename _Tp> void _write(_Tp x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename _Tp> void write(_Tp x) { if(x < 0) x = -x,pc('-'); _write(x); }
template<typename _Tp> void writeln(_Tp x) { write(x); puts(""); }
const int N = 2e5 + 10;
int n,q;
string s1[N],s2[N];
int a[N],b[N];
//vector<int> ids[5000010 << 1];
//const int add = 5e6;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(); q = read();
	for(int i = 1;i <= n;i++)	cin >> s1[i] >> s2[i];
	bool flag = true;
	for(int i = 1;i <= n;i++)
		if(flag)
			for(int j = 0;j < s1[i].size();j++)
				if(s1[i][j] != 'a' && s1[i][j] != 'b')
				{ flag = false; break; }
	for(int i = 1;i <= n;i++)
		if(flag)
			for(int j = 0;j < s2[i].size();j++)
				if(s2[i][j] != 'a' && s2[i][j] != 'b')
				{ flag = false; break; }
	if(flag)
	{
		for(int i = 1;i <= n;i++)
			for(int j = 0;j < s1[i].size();j++)
				if(s1[i][j] == 'b')	a[i] = j;
		for(int i = 1;i <= n;i++)
			for(int j = 0;j < s2[i].size();j++)
				if(s2[i][j] == 'b')	b[i] = j;
//		for(int i = 1;i <= n;i++)	ids[b[i] - a[i] + add].push_back(i);
		string s,t;
		while(q--)
		{
			cin >> s >> t;
			if(s.size() != t.size()) { puts("0"); continue; }
			int k1,k2;
			for(int j = 0;j < s.size();j++)
				if(s[j] == 'b')	k1 = j;
			for(int j = 0;j < s.size();j++)
				if(t[j] == 'b')	k2 = j;
			int cnt = 0;
//			for(int i = 0;i < ids[k2 - k1 + add].size();i++)
//				if(k1 >= a[ids[k2 - k1 + add][i]] && k2 >= b[ids[k2 - k1 + add][i]])
//					cnt++;
			for(int i = 1;i <= n;i++)
				if(k2 - k1 == b[i] - a[i] && k1 >= a[i] && k2 >= b[i] && n - k1 - 1 >= s1[i].size() - a[i] - 1 && n - k2 - 1 >= s2[i].size() - b[i] - 1) 
					cnt++;
			writeln(cnt);
		}
		return 0;
	}
	string s,t;
	while(q--)
	{
		cin >> s >> t;
		if(s.size() != t.size()) { puts("0"); continue; }
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			int k = s.find(s1[i]);
			while(k != -1)
			{
				for(int j = k;j <= k + s1[i].size() - 1;j++)
					s[j] = s2[i][j - k];
				if(s == t)	cnt++;
				for(int j = k;j <= k + s1[i].size() - 1;j++)
					s[j] = s1[i][j - k];
				k = s.find(s1[i],k + 1);
			}
		}
		writeln(cnt);
	}
	return 0;
}
/*

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
