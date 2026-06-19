#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,L=5e6+5;

int n,q,cntb1,cntb2,b[N][5],tb1,tb2,delb[L],szt,szs,sz,cnt;
ll ans,ansb;
bool B=0;
string s[N][5],t1,t2;

int main()
	{
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		sz=s[i][1].size();
		if(!B) continue;
		cntb1=0,cntb2=0;
		for(int j=0;j<sz;j++)
		{
			if(s[i][1][j]!='a'&&s[i][1][j]!='b'&&s[i][2][j]!='a'&&s[i][2][j]!='b') B=0;
			if(s[i][1][j]=='b') cntb1++;
			if(s[i][2][j]=='b') cntb2++;
			if(cntb1>1||cntb2>1) B=0;
		}
	}
	if(B)
	{
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			while(s[i][1][cnt]!='b') cnt++;
			b[i][1]=cnt+1;
			cnt=0;
			while(s[i][2][cnt]!='b') cnt++;
			b[i][2]=cnt+1;
		}
		for(int i=1;i<=q;i++)
		{
			ans=0;
			cin>>t1>>t2;
			cnt=0;
			while(t1[cnt]!='b') cnt++;
			tb1=cnt+1;
			cnt=0;
			while(t2[cnt]!='b') cnt++;
			tb2=cnt+1;
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int I=1;I<=q;I++)
	{
		cin>>t1>>t2;
		szt=t1.size(),ans=0;
		for(int i=1;i<=n;i++)
		{
			szs=s[i][1].size();
			for(int j=1;j<=szt-szs+1;j++)
			{
				bool ok=1;
				for(int k=0;k<j-1;k++)
				{
					if(t1[k]!=t2[k])
					{
						ok=0;
						break;
					}
				}
				for(int k=j+szs;k<=szt;k++)
				{
					if(t1[k-1]!=t2[k-1])
					{
						ok=0;
						break;
					}
				}
				for(int k=j;k<=j+szs-1;k++)
				{
					if(s[i][1][k-j]!=t1[k-1])
					{
						ok=0;
						break;
					}
				}
				if(!ok) continue;
				for(int k=j;k<=j+szs-1;k++)
				{
					if(s[i][2][k-j]!=t2[k-1])
					{
						ok=0;
						break;
					}
				}
				if(ok) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	}
