#include<bits/stdc++.h>
using namespace std;
int n,q,sl[200005][5];
string s[200005][5],t1,t2,t3,t4;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
		s[i][1] = " " + s[i][1];
		s[i][2] = " " + s[i][2];
		s[i][3] = " ";
		s[i][4] = " ";
		int l,r;
		for(int j = 1;j < s[i][1].size();j++)
		{
			if(s[i][1][j] != s[i][2][j])
			{
				l = j;
				break;
			}
		} 
		for(int j = s[i][1].size()-1;j >= 1;j--)
		{
			if(s[i][1][j] != s[i][2][j])
			{
				r = j;
				break;
			}
		}
		sl[i][1] = l;
		sl[i][2] = r;
		for(int j = l;j <= r;j++)
		{
			s[i][3] += s[i][1][i];
			s[i][4] += s[i][2][i];
		}
	}
	while(q--)
	{
		t3 = "";
		t4 = "";
		cin >> t1 >> t2;
		int x = t1.size();
		t1 = " " + t1;
		t2 = " " + t2;
		int l,r,cnt = 0;
		for(int j = 1;j < t1.size();j++)
		{
			if(t1[j] != t2[j])
			{
				l = j;
				break;
			}
		} 
		for(int j = t1.size()-1;j >= 1;j--)
		{
			if(t1[j] != t2[j])
			{
				r = j;
				break;
			}
		}
		for(int i = l;i <= r;i++)
		{
			t3 += t1[i];
			t4 += t2[i];
		}
		for(int i = 1;i <= n;i++)
		{
			if(s[i][3] == t3 && s[i][4] == t4 && l - sl[i][1] + 1 >= 1 && r - sl[i][2] + s[i][1].size() <= t1.size())
			{
				bool flag = 1;
				for(int j = sl[i][1];j >= 1;j--)
				{
					if(t1[l - sl[i][1] + j] != s[i][1][j]) 
					{
						flag = 0;
						break;
					}
				}
				if(flag)
				{
					for(int j = sl[i][2];j < s[i][1].size();j++)
					{
						if(t1[r - sl[i][2] + j] != s[i][1][j]) 
						{
							flag = 0;
							break;
						}
					}
					if(flag)
					{
						cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
