#include<iostream>
#include<string>
using namespace std;
int cnt[10];
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0'] ++;
	for (int i = 9; i >= 0; i--)
		while (cnt[i] --) printf("%d" , i);
	return 0;
}
