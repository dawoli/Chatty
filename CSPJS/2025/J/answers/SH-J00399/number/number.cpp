#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int a[maxn];
int cnt=0;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')
		{
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
