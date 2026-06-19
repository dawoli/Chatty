#include <iostream>
using namespace std;
int t[1005];
bool tt[1005];
char s[5];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	char a;
	char b;
	t['D']=0;
	t['C']=1;
	t['H']=2;
	t['S']=3;
	for (int i = 1; i <= 9; i++)
	{
		t['0' + i] = i - 1;
	}
	t['A']=0;
	t['T']=9;
	t['J']=10;
	t['Q']=11;
	t['K']=12;
	for (int i = 1; i <= n; i++)
	{
		cin>>s;
		a = s[1];
		b = s[0];
		tt[t[a] + t[b] * 13] = true;
	}
	int result = 0;
	for (int i = 0; i < 52; i++)
	{
		if (!tt[i])
		{
			result++;
		}
	}
	cout<<result;
 } 
