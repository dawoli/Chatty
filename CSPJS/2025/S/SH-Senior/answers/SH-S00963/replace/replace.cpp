#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	if(n>1000)
	{
		while(q--)printf("0\n");
		return 0;
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t1.size()-s1[i].size()+1;j++)
			{
				bool f=0;
				for(int k=0;k<s1[i].size();k++)
				{
					//cout<<k<<" ";
					if(t1[j+k]!=s1[i][k])
					{
						f=1;
						break;
					}
				}
				if(f)
				{
					//cout<<endl<<1<<" "<<i<<" "<<j<<endl;
					continue;
				}
				for(int k=0;k<t1.size();k++)
				{
					//cout<<k<<" ";
					if(k>=j&&k<j+s2[i].size())
					{
						if(s2[i][k-j]!=t2[k])
						{
							f=1;
							break;
						}
					}
					else
					{
						if(t1[k]!=t2[k])
						{
							f=1;
							break;
						}
					}
				}
				if(f)
				{
					//cout<<endl<<2<<" "<<i<<" "<<j<<endl;
					continue;
				}
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
