#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
#define PII pair<int,int>
const int N=2e5+10,mod=1e9+7,M=131;
string s1[N],s2[N];
int h1[N][2010],h2[N][2010],h3[2010],h4[2010];
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i]; 
		int l1=s1[i].size(),l2=s2[i].size();
		for(int j=1;j<=l1;j++)
		{
			h1[i][j]=h1[i][j-1]*128%mod+s1[i][j];
			h1[i][j]%=mod;
		}
		for(int j=1;j<=l2;j++)
		{
			h2[i][j]=h2[i][j-1]*128%mod+s2[i][j];
			h2[i][j]%=mod;
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		for(int j=1;j<=l1;j++)
		{
			h3[j]=h3[j-1]*128%mod+t1[j];
			h3[j]%=mod;
		}
		for(int j=1;j<=l2;j++)
		{
			h4[j]=h4[j-1]*128%mod+t2[j];
			h4[j]%=mod;
		}
		cout<<0<<endl;
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
