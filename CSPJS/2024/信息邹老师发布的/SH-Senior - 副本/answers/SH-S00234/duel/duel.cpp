#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,m; cin>>n;
	for (int i=0;i<n;i++)
	{
		int t; cin>>t;
		mp[t]++;
		m=max(m,mp[t]);
	}
	cout<<m;
	return 0;
 } 
