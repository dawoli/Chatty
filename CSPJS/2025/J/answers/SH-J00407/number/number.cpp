#include<bits/stdc++.h>
using namespace std;
int n[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(auto& it:a)
	{
		if(it<='9'&&it>='0')
		{
			n[it-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=n[i];j++)
		{
			cout<<i;
		}
	}
	return 0;	
}
