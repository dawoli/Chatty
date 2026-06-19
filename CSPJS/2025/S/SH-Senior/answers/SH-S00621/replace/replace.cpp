#include<bits/stdc++.h>
using namespace std;
int n,q,p=0,ans;
string a[200001],b[200001],aa,bb,cc;
bool t=true;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin >>aa>>bb;
		cc=aa;
		for(int k=1;k<=n;k++)
		{
			for(int j=0;j<aa.size();j++)
			{
				if(aa.size()-j>=a[k].size())
				{
					t=true;
					p=0;
					while(p<a[k].size() && t)
					{
						t= a[k][p]==aa[j+p];
						p++;
					}
					if(t)
					{
						p=0;
						while(p<a[k].size() && t)
						{
							cc[j+p]=b[k][p];
							p++;
						}
						if(cc==bb)
						{
							ans++;
							//printf("%d %d\n",i,k);
						}
						cc=aa;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
