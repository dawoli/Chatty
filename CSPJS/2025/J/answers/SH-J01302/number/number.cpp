#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
int b[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
			cnt++;
		}
	}
	for(int i = 0; i < cnt; i++)
	{
		b[i] = a[i];
	}
	sort(b, b + cnt);
	for(int i = cnt - 1; i >= 0; i--)
	{
		cout << b[i]; 
	}
	cout << endl;
 } 
