#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=509;
const int MOD=998244353;
int n,m,cnt=0,ans=0;
string s;
int c[N],id[N],zero;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		id[i]=i;
		zero+=(c[i]==0);
	}
	if(m==n)
	{
		bool flag=1;
		if(zero>0)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=m;i++)
		{
			ans=(ans*i)%MOD;
		}
		cout<<ans;
		return 0;
	}
	do
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[id[i]])
			  cnt++;
			else if(s[i]=='0')
			  cnt++;
		}
		if(n-cnt>=m)
		{
//			cout<<c[id[1]]<<" "<<c[id[2]]<<" "<<c[id[3]]<<endl;
			ans=(ans+1)%MOD;
		}
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
	return 0;
}

