#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		int ans = 0;
		for(int i = 0;i<a.size();i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(i+s[j].a.size()>a.size())
				{
					continue;
				}
				bool flag = true;
				for(int k = 0;k<s[j].a.size();k++)
				{
					if(a[i+k]!=s[j].a[k]||b[i+k]!=s[j].b[k])
						flag = false;

					if(flag==false)
						break;
				}
				if(flag==true)
				{
					for(int k = 0;k<i;k++)
					{
						if(a[k]==b[k])
							continue;
						else
							flag = false;
					}
					for(int k = i+s[j].a.size();k<a.size();k++)
					{
						if(a[k]==b[k])
							continue;
						else
							flag = false;
					}
				}
				if(flag==true)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
