#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	int a[1000007];
	int cnt = 0;
	cin >> s1;
	for(int i = 0 ; i < s1.size() ; i++)
	{
		if('0'<=s1[i] && '9'>=s1[i])
		{
			cnt++;
			a[cnt] = s1[i] - '0';
		}else
		{
			continue;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i = 1 ; i <= cnt ; i++)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
