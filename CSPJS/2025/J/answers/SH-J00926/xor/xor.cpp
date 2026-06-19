#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int n,k,a[N];
string k1,s[N];

string change(int n)
{
	vector <char> s;
	char ans[21];
	while (n != 0)
	{
		s.push_back(n%2+'0');
		n /= 2;
	}
	int cnt = s.size()-1;
	for (char c : s)
	{
		ans[cnt] = c;
		cnt--;
	}
	return ans;
}

int change1(string s)
{
	int ans = 0;
	for (int i = s.length()-1;i >= 0;i--)
	{
		ans += s[i]-'0';
		ans *= 2;
	}
	return ans;
}

string yh(int a,int b)
{
	string a1 = change(a),b1 = change(b);
	if (a == b) return "0";
	if (a == 0) return b1;
	if (b == 0) return a1;
	char ans[21];
	int l1 = a1.length(),l2 = b1.length();
	int l = max(l1,l2);
	for (int i = 0;i < l;i++)
	{
		if (l2 -i -1 < 0)
		{
			ans[i] = a1[l1-i-1];
			continue;
		}
		if (l1 -i -1 < 0)
		{
			ans[i] = b1[l2-i-1];
			continue;
		}
		if (a1[l1-i-1] != b1[l2-i-1])
		{
			ans[i] = '1';
		}
		else
		{
			ans[i] = '0';
		}
	}
	char ans1[21];
	bool t = false;
	for (int i = 0,j = 0;i < l;i++)
	{
		if (ans[l-1-i] == '1') t = true;
		if (t)
		{
			ans1[j] = ans[l-1-i];
			j++;
		}
	}
	return ans1;
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	k1 = change(k);
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s[i] = yh(a[i],change1(s[i-1]));
	}
	int c = 0,cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		if (yh(change1(s[i]),c) == k1)
		{
			cnt++;
			c = change1(s[i]);
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
