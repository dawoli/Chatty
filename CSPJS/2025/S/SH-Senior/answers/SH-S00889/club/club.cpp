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
const int N = 1e5 + 10;
int n;
struct node
{
	int a,b,c;
	int id1,id2,id3;
} a[N];
int val1(int id)
{
	if(a[id].id1 == 1)	return a[id].a;
	if(a[id].id1 == 2)	return a[id].b;
	if(a[id].id1 == 3)	return a[id].c;
	return -1;
}
int val2(int id)
{
	if(a[id].id2 == 1)	return a[id].a;
	if(a[id].id2 == 2)	return a[id].b;
	if(a[id].id2 == 3)	return a[id].c;
	return -1;
}
int val3(int id)
{
	if(a[id].id3 == 1)	return a[id].a;
	if(a[id].id3 == 2)	return a[id].b;
	if(a[id].id3 == 3)	return a[id].c;
	return -1;
}
bool cmp(int x,int y)
{
	if(val3(x) - val2(x) != val3(y) - val2(y))	return val3(x) - val2(x) > val3(y) - val2(y);
	if(val3(x) - val2(x) != val3(y) - val2(y))	return val3(x) - val1(x) > val3(y) - val1(y);
	if(val3(x) != val3(y))	return val3(x) > val3(y);
}
void solve()
{
	n = read();
	for(int i = 1;i <= n;i++)
		a[i].a = read(),a[i].b = read(),a[i].c = read();
	for(int i = 1;i <= n;i++)
	{
		if(a[i].a <= a[i].b && a[i].b <= a[i].c)
			a[i].id1 = 1,a[i].id2 = 2,a[i].id3 = 3;
		else if(a[i].a <= a[i].c && a[i].c <= a[i].b)
			a[i].id1 = 1,a[i].id2 = 3,a[i].id3 = 2;
		else if(a[i].b <= a[i].a && a[i].a <= a[i].c)
			a[i].id1 = 2,a[i].id2 = 1,a[i].id3 = 3;
		else if(a[i].b <= a[i].c && a[i].c <= a[i].a)
			a[i].id1 = 2,a[i].id2 = 3,a[i].id3 = 1;
		else if(a[i].c <= a[i].a && a[i].a <= a[i].b)
			a[i].id1 = 3,a[i].id2 = 1,a[i].id3 = 2;
		else
			a[i].id1 = 3,a[i].id2 = 2,a[i].id3 = 1;
	}
	vector<int> v1,v2,v3;
	for(int i = 1;i <= n;i++)
		if(a[i].id3 == 1)	v1.push_back(i);
		else if(a[i].id3 == 2)	v2.push_back(i);
		else	v3.push_back(i);
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);
	sort(v3.begin(),v3.end(),cmp);
	if(v1.size() > n / 2)
		while(v1.size() > n / 2)
		{
			int id = v1.back(); v1.pop_back();
			if(a[id].id2 == 2)
				if(v2.size() <= n / 2)	v2.push_back(id);
				else	v3.push_back(id);
			else
				if(v3.size() <= n / 2)	v3.push_back(id);
				else 	v2.push_back(id);
		}
	if(v2.size() > n / 2)
		while(v2.size() > n / 2)
		{
			int id = v2.back(); v2.pop_back();
			if(a[id].id2 == 1)
				if(v1.size() <= n / 2)	v1.push_back(id);
				else	v3.push_back(id);
			else
				if(v3.size() <= n / 2)	v3.push_back(id);
				else 	v1.push_back(id);
		}
	if(v3.size() > n / 2)
		while(v3.size() > n / 2)
		{
			int id = v3.back(); v3.pop_back();
			if(a[id].id2 == 1)
				if(v1.size() <= n / 2)	v1.push_back(id);
				else	v2.push_back(id);
			else
				if(v2.size() <= n / 2)	v2.push_back(id);
				else 	v1.push_back(id);
		}
	int ans = 0;
	for(int i = 0;i < v1.size();i++)	ans += a[v1[i]].a;
	for(int i = 0;i < v2.size();i++)	ans += a[v2[i]].b;
	for(int i = 0;i < v3.size();i++)	ans += a[v3[i]].c;
	writeln(ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while(T--)	solve();
	return 0;
}
