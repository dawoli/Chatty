#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a,char b)
{
	return a > b;
}
int main()
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	sort(s.begin(),s.end(),cmp);
	for (int i = 0;i < s.size();i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
			cout << s[i];
	}
	cout << endl;
	return 0; 
}
