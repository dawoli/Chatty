#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
string s[200005][3];
int diff(string A, string B)
{
	int cnt = 0;
	for(int i = 0; i < A.length(); i++)
	{
		if(A[i] != B[i]) cnt++;
	}
	return cnt;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		ans = 0;
		string a, b;
		cin>>a>>b;
		for(int i = 1; i <= n; i++)
		{
			if(diff(a, b) == diff(s[i][1], s[i][2]) && a.find(s[i][1]) < a.length() && b.find(s[i][2]) < b.length()) 
			{
				cout<<i<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
