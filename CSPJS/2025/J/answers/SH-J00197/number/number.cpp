#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> v;
int main ()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
			v.push(s[i]-'0');
        }
    }
    if (v.empty() || v.top()==0)
    {
        cout << 0;
        return 0;
    }
	while (!v.empty())
	{
		cout << v.top();
		v.pop();
	}
	return 0;
}
