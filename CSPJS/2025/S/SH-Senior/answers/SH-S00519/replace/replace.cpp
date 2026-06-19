#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		int flag=1;
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			flag=0;
		}else{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=t1.size()-s1[i].size();j++)
				{
					if(t1.size()>=s1[i].size())
					{
						string t3=t1;
						if(t3.substr(j,s1[i].size())==s1[i])
						{
							for(int k=j;k<j+s1[i].size();k++)
							{
								t3[k]=s2[i][k-j];
							}
						}
						if(t2==t3)
						{
							ans++;
							//cout<<i<<endl;
						}
					}
					
				}
			}
		}
		if(flag)
		{
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
