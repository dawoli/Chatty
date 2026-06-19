#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int N=200005,M=5000005,B=29,mod=998244353;
int n,q;
bool pre[M],suf[M];
char s[2][M],t[2][M];
map<int,map<int,int> >mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[0]>>s[1];
		int h1=0,h2=0,len=strlen(s[0]);
		for(int j=0;j<len;j++) h1=(h1*B+s[0][j]-'a'+1)%mod,h2=(h2*B+s[1][j]-'a'+1)%mod;
		mp[h1][h2]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[0]>>t[1];
		int len1=strlen(t[0]),len2=strlen(t[1]);
		if(len1!=len2)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int j=0;j<len1;j++)
		{
			bool cur=(t[0][j]==t[1][j]);
			if(!j) pre[j]=cur;
			else pre[j]=pre[j-1]&cur;
		}
		for(int j=len1-1;j>=0;j--)
		{
			bool cur=(t[0][j]==t[1][j]);
			if(j==len1-1) suf[j]=cur;
			else suf[j]=suf[j+1]&cur;
		}
		int ans=0;
		for(int j=0;j<len1;j++)
		{
			if(j&&(!pre[j-1])) break;
			int h1=0,h2=0;
			for(int k=j;k<len1;k++)
			{
				h1=(h1*B+t[0][k]-'a'+1)%mod,h2=(h2*B+t[1][k]-'a'+1)%mod;
				if(k==len1-1||suf[k+1]) ans+=mp[h1][h2];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
