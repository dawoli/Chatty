#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string a;
map<string,bool> m;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(!m[a])
		{
			m[a]=true;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
