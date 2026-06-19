#include<iostream>
#include<unordered_map>
using namespace std;
typedef unsigned long long ll;
const ll P = 31;
int l[200005];
ll f[2][5000005] , a[200005] , b[200005] , p[5000005];
void math(const string &s , bool t)
{
	for (int i = 1; i <= s.size(); i++) f[t][i] = f[t][i - 1] * P + s[i - 1] - 'a' + 1;
}
ll get(bool t , int x , int y)
{
	return f[t][y] - f[t][x - 1] * p[y - x + 1];
}
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	p[0] = 1;
	for (int i = 1; i <= 2e6; i++) p[i] = p[i - 1] * P; 
	int n , q; scanf("%d%d" , &n , &q);
	for (int i = 1; i <= n; i++)
	{
		string s1 , s2; cin >> s1 >> s2;
		l[i] = s1.size();
		math(s1 , 0);
		math(s2 , 1);
		a[i] = f[0][l[i]];
		b[i] = f[1][l[i]];
		
	}
	while (q --)
	{
		string s , t; cin >> s >> t;
		if (s.size() != t.size())
		{
			printf("0\n");
			continue;
		}
		math(s , 0);
		math(t , 1);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j + l[i] - 1 <= s.size(); j++)
				if (get(0 , j , j + l[i] - 1) == a[i] && get(1 , j , j + l[i] - 1) == b[i] && get(0 , 1 , j - 1) == get(1 , 1 , j - 1) && get(0 , j + l[i] , s.size()) == get(1 , j + l[i] , s.size()))
					ans ++;
		printf("%lld\n" , ans);
	}
	return 0;
}
