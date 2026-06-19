#include<bits/stdc++.h>
using namespace std;
map<string,long long> bh;
long long n,m,i,j,s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		string w;
		cin>>w;
		if(bh[w]==0)
		{
		bh[w]=i;
		s++;	
		}
	}
	cout<<52-s;
	return 0;
}
