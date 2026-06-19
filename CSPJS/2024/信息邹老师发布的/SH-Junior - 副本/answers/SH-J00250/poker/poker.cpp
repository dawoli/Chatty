#include<bits/stdc++.h>
using namespace std;
int n;
map<string,bool> pokermap;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string poker;
		cin>>poker;
		pokermap[poker]=true;
	}
	cout<<52-pokermap.size();
	return 0;
} 
