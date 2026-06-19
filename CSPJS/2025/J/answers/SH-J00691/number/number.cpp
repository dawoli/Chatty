#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,b[15];
string a;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(auto it:a)
	{
		if(it-'0'<=9&&it-'0'>=0)
		{
			b[it-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
} 
