#include<iostream>
#include<map>
using namespace std;
map<string,int> mp;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52; cin>>n;
	while(n--)
	{
		string s; cin>>s;
		if (!mp[s])
		{
			ans--;
			mp[s]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
