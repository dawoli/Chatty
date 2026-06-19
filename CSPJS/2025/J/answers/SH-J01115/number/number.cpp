#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n = s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cnt[int(s[i])-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		cout<<i;
	}
	
	
	
	
	return 0;
}
