#include<bits/stdc++.h>
using namespace std;
int n,a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
}
