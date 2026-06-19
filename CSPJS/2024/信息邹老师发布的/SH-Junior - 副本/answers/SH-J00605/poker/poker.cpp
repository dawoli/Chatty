#include <bits/stdc++.h>
using namespace std;
string vis[15];
int cnt=0;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int pos;
		bool flag=true;
		if (s[1]=='A')pos=1;
		else if (s[1]=='T')pos=10;
		else if (s[1]=='J')pos=11;
		else if (s[1]=='Q')pos=12;
		else if (s[1]=='K')pos=13;
		else pos = int(s[1]-'0');
		for (int i = 0;i<vis[pos].size();i++)
		{
			if(s[0]==vis[pos][i])
			{
				flag=false;
				break;
			}
		}
		if (flag)vis[pos]+=s[0];
	}
	for (int i = 1;i<=13;i++)cnt+=vis[i].size();
	cout << 52-cnt; 
	fclose(stdin);
	fclose(stdin);
	return 0;
}
