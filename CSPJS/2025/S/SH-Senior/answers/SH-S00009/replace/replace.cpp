#include<bits/stdc++.h>
using namespace std;
const int base=30,mod=1e9+7;
int n,q,en,l,r,ans=0,f[5000010],b[5000010],c[5000010],len1,len2,a[200010][5];
string s,s1,s2;
int ha()
{
	long long sum=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		sum=(sum*base)%mod+s[i]-'a';
		sum%=mod;
	}
	return sum;
}
int hab()
{
	int len=s1.length();
	for(int i=0;i<len;i++)
	{
		b[i+1]=(b[i]*base)%mod+s1[i]-'a';
		b[i+1]%=mod;
	}
	return 0;
}
int hac()
{
	int len=s2.length();
	for(int i=0;i<len;i++)
	{
		c[i+1]=(c[i]*base)%mod+s2[i]-'a';
		c[i+1]%=mod;
	}
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	f[++en]=30;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[i][1]=ha();
		cin>>s;
		a[i][2]=ha();
		a[i][3]=s.length();
//		cout<<a[i][1]<<" "<<a[i][2]<<endl;
	}
	while(q--)
	{
		ans=0;
		cin>>s1;
		len1=s1.length();
		if(len1>en)
		{
			for(int i=en+1;i<=len1;i++)
				f[i]=f[i-1]*base%mod;
			en=len1;
		}
		hab();
		cin>>s2;
		len2=s2.length();
//		cout<<len1<<"&"<<len2<<endl;
		if(len2>en)
		{
			for(int i=en+1;i<=len2;i++)
				f[i]=f[i-1]*base%mod;
			en=len2;
		}
//		cout<<en<<endl;
		hac();
		for(int i=0;i<min(len1,len2);i++)
		{
			if(s1[i]!=s2[i])
			{
				l=i;
				break;
			}
		}
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		for(int i=min(len1,len2)-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				r=i;
				break;
			}
		}
		l++,r++;
//		cout<<l<<" "<<r<<endl;
//		for(int i=1;i<=len1;i++)
//		{
//			cout<<b[i]<<" ";
//		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j+a[i][3]-1<=min(len1,len2);j++)
			{
//				cout<<i<<" "<<j<<" "<<b[j+a[i][3]-1]<<" "<<b[j-1]<<" "<<f[a[i][3]]<<" "<<a[i][1]<<endl;
				if(b[j+a[i][3]-1]-b[j-1]*f[a[i][3]]==a[i][1] && c[j+a[i][3]-1]-c[j-1]*f[a[i][3]]==a[i][2])
				{
					if(j<=l && j+a[i][3]-1>=r)
					{
//						cout<<i<<endl;
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
