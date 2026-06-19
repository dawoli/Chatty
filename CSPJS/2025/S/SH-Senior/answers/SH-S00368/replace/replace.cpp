#include<bits/stdc++.h>
using namespace std;

const int N=200005;
string s[N][2];
int d[N],sz[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int ans=0;
	string t1,t2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][0].size();
		for(int j=0;j<sz[i];j++)
			if(s[i][0][j]!=s[i][1][j])
			{
				d[i]=j;
				break;
			}
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		int fd=-1,ld=-1;
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		for(int i=0;i<len1;i++)
			if(t1[i]!=t2[i])
			{
				if(fd==-1) fd=i;
				ld=i;
			}
		for(int i=fd;i<=fd;i++)
		{
			for(int j=1;j<=n;j++)
				if(t1[i]==s[j][0][d[j]]&&t2[i]==s[j][1][d[j]])
				{
					if(sz[j]-d[j]>len1-i||i<d[j]) continue;
					if(i-d[j]+sz[j]<=ld) continue;
					bool flag=1;
					for(int k=1;k+d[j]<sz[j]&&k+i<len1;k++)
						if(t1[i+k]!=s[j][0][d[j]+k]||t2[i+k]!=s[j][1][d[j]+k])
						{
							flag=0;
							break;
						}
					if(!flag) continue;
					for(int k=1;k<=d[j]&&k<=i;k++)
						if(t1[i-k]!=s[j][0][d[j]-k]||t2[i-k]!=s[j][1][d[j]-k])
						{
							flag=0;
							break;
						}
					if(flag) ans++;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
