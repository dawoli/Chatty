#include<bits/stdc++.h>
using namespace std;

int num[1000006];
string s;
int l;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	l = s.length();
	for(int i = 0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')num[++num[0]] = int(s[i]-'0');
	}
	sort(num+1,num+num[0]+1);
	for(int i = num[0];i>=1;i--)cout<<num[i];
	return 0;
}
