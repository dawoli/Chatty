#include<bits/stdc++.h>
using namespace std;
int n;
int f[15];
string x;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	n=x.length();
	for(int i=0;i<n;i++)
	{
		if('0'<=x[i]&&x[i]<='9')f[x[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)cout<<i;
	}
	return 0;
}
