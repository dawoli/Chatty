#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
struct STR
{
	string x,y;
	int len;
	bool operator<(const STR &a)const
	{
		return len<a.len;
	}
};
int n,Q,ans=0;
STR s[N];
string t[N][2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y;
		s[i].len=s[i].x.size();
	}
	sort(s+1,s+1+n);
	int t1,t2;
	for(int q=1;q<=Q;q++)
	{
		cin>>t[q][0]>>t[q][1];
		if(t[q][0].size()!=t[q][1].size())
		{
			cout<<0<<endl;
			continue;
		}
		ans=0;
		int len=t[q][0].size();
//		cout<<len<<endl;
		int tl,tr,lr,l=0;
		for(tl=0;tl<len;tl++)
		  if(t[q][0][tl]!=t[q][1][tl])
			break;
		for(tr=len-1;tr>0;tr--)
		  if(t[q][0][tr]!=t[q][1][tr])
			break;
		if(tr<tl)lr=0;
		else lr=(tr-tl+1);
//		cout<<tl<<" "<<tr<<" "<<lr<<endl;
		for(int i=1;i<=n;i++)
		{
			if(s[i].len<lr)continue;
			l=s[i].len;
			for(int j=max(0,tr-l+1);j<=min(tl,len-1);j++)
			{
//				cout<<i<<" "<<t[q][0].substr(j,l)<<" "<<s[i].x<<endl;
				if(t[q][0].substr(j,l)!=s[i].x)continue;
				if(s[i].y==t[q][1].substr(j,l))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

