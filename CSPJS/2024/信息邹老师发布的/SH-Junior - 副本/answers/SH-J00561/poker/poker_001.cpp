#include<bits/stdc++.h>
using namespace std;
map<string,bool> st;
int n,cnt = 52;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		if(!st.count(s))
		{
			cnt--;
		}
	}
	cout << cnt;
	return 0;
}
