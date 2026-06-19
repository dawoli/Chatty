#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

string s1[20005];
string s2[20005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int x,q;
	cin >> x >> q;
	for(int i = 1;i <= x;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= q;i++)
	{
		string m,n;
		cin >> m >> n;
		int cnt = 0;
		for(int i = 0;i < m.length();i++)
		{
			for(int j = i + 1;j < m.length();j++)
			{
					string s = m.substr(i,j + 1);
					for(int p = 1;p <= x;p++)
					{
						if(s1[p] == s)
						{
							string sk = m.substr(0,i) + s2[p] + m.substr(j + 1,m.length(); 
							cout << sk <<endl;
							if(sk == n) cnt++;
						}
					}
			}
		}
		cout << cnt <<endl;
	}
	return 0;	
} 
