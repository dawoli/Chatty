#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
string s1[200005],s2[200005],t[3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	if(q>1000)
	{
		while(q--) printf("0\n");
		return 0;
	}
	while(q--)
	{
		cin>>t[1]>>t[2];
		if(t[1].size()!=t[2].size())
		{
			printf("0\n");
			continue;
		}
		int l=t[1].size(),ans=0;
		for(int i=1;i<=n;i++)
		{
			int ll=s1[i].size();
			bool f=0;
			for(int j=0;j<l;j++)
			{
				int p=0,x=j;
				while(t[1][x]==s1[i][p]&&t[2][x]==s2[i][p]&&x<l&&p<ll) x++,p++;
//				printf("%d %d\n",x,p);
				if(p==ll&&!f)
				{
					f=1;
				}
				else if(p==ll&&f)
				{
					f=0;
					break;
				}
			}
			if(f) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
