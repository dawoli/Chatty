#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

const int N = 2e5 + 5;
int cnt = 0;
string s[N][3];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	while(q--)
	{
		cnt = 0;
		string a,b;
		cin >> a >> b;
		for(int i = 0;i < a.size();i++)
		{
			string x = a.substr(0,i);
			for(int j = 0;j < a.size() - i + 1;j++)
			{
				string y = a.substr(i,j);
				string z = a.substr(i + j,a.size() - i - j);

//						printf("x = ");
//						cout << x;
//						printf(",y = ");
//						cout << y;
//						printf(",z = ");
//						cout << z << endl;
				for(int k = 1;k <= n;k++)
				{
					if(y == s[k][1])
					{
						y = s[k][2];
						if(x + y + z == b) cnt++;
						y = s[k][1];
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}