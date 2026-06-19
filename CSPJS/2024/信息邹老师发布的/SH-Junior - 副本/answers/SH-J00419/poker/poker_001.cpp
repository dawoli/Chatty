#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
map<string,int>mp;
int nS=0;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(!mp.count(s))mp[s]=++nS;
	}
	cout<<(52-nS);
	return 0;
}
