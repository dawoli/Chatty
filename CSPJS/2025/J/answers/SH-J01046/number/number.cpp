#include<bits/stdc++.h>
using namespace std;
string s;
char sz[1000005];
bool cmp(char a,char b)
{
	return a > b;
}
int zz = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			sz[zz ++] = s[i];
	}
	zz --;
	sort(sz,sz + zz,cmp);
	for(int i = 0;i <= zz;i ++)
	{
		cout << sz[i];
	}
	return 0;
}
