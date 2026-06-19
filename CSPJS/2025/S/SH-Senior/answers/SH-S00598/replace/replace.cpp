#include<bits/stdc++.h>
using namespace std;

pair<string, string> a[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	while(q--)
	{
		long long ans=0;
		string s, tar;
		cin>>s>>tar;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<=s.size()-a[i].first.size()+1; j++)
			{
				if(s.substr(j, a[i].first.size())==a[i].first)
				{
					string x=s;
					for(int k=j; k<=j+a[i].first.size()-1; k++)
					{
						x[k]=a[i].second[k-j];
					}
					if(x==tar)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
