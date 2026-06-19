#include<bits/stdc++.h> 
using namespace std;
int l,a[50],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	l=s.size();
	for(int i=0;i<=l;i++)
	{
		if(s[i]<='9' and s[i]>='0')
		{
			a[s[i]-'0']++;
			k++;
		}
	}
	if(a[0]==k)
	{
		cout<<"0";
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
