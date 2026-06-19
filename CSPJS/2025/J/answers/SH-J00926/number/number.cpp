#include <bits/stdc++.h>
using namespace std;

bool cmp(const int& a,const int&b)
{
	return a > b;
}

const int N = 1e6+5;
char s[N];
int ans[N],cnt = 1;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	int a = strlen(s);
	for (int i = 0;i < a;i++)
	{
		if (isdigit(s[i]))
		{
			ans[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(ans+1,ans+cnt,cmp);
	for (int i = 1;i < cnt;i++)
	{
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
