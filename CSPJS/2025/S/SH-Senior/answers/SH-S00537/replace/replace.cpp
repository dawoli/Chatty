#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n,q,ans;
string a[2],s[10005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		ans=0;
		cin>>a[0]>>a[1];
		
		if(a[0].size()!=a[1].size())
		{
			printf("0\n");
			continue;
		}
		
		for(int k=0;k<a[0].size();k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(k+s[i][0].size()-1<a[0].size()&&a[0].substr(k,s[i][0].size())==s[i][0]&&
				a[1]==a[0].substr(0,k)+s[i][1]+a[0].substr(k+s[i][0].size()))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
