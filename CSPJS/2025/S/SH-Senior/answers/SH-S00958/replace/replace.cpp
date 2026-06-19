#include<bits/stdc++.h>
using namespace std;

int n,q,len,qlen,fla,comlen,flag,ans,st,en;
string s[200005][2];
string s1,s2,t1,t2;
char a[5000005],b[5000005],c;
char acom[5000005],bcom[5000005];
bool vis[26];
bool fB=1;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		len=t1.length();
		for(int j=1;j<=len;j++)
		{
			if(t1[j]!=t2[j])
			{
				st=j;
				while(t1[j+comlen]!=t2[j+comlen])
				{
					comlen++;
				}
				en=st+comlen-1;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			flag=0;
			ans=0;
			s1=s[j][0];
			s2=s[j][1];
			int slen=s1.length();
			if(slen!=en-st+1)continue;
			
			for(int k=1;k<=slen;k++) 
			{
				if(s1[k]!=t1[k]||s2[k]!=t2[k])
				{
					flag=1;
					break;
				}
			}
			if(!flag)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
