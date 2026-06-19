#include<bits/stdc++.h>
using namespace std;

int n,ans;
map<string,int> m;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		if(m[x]==0)
		{
			ans++;m[x]=1;
		}
	}
	cout<<52-ans;
	return 0;
}
