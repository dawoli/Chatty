#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

bool cmp(int abc, int bcd)
{
	return abc > bcd;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	cin>>str;
	int len = str.length();
	for(int ini = 0; ini < len; ini++)
	{
		if(str[ini] >= '0' && str[ini] <= '9')
		{
			vec.push_back(str[ini] - '0');
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	for(auto ans : vec)
	{
		cout<<ans;
	}
	return 0; 
}
