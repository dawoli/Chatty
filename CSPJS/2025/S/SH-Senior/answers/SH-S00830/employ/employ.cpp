#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=510,Mod=998244353;
int n,m,nd[Maxn],c[Maxn],d[Maxn],ans;
string s;
int pai(int x)
{
	if(x==0) return 1;
	return (x*pai(x-1))%Mod;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=1;
	for(int i=0;i<n;i++)
	{
		nd[i+1]=s[i]-'0';
		if(nd[i+1]==0) f=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		d[i]=i;
		if(c[i]==0) ans++;
	}
	if(ans>n-m) cout<<"0\n";
	if(m==1)
	{
		sort(c+1,c+1+n,cmp);
		int cnt=pai(n-1);
		ans+=c[1]*cnt; ans%=Mod;
		for(int i=c[1]+1;i<=n;i++)
		{
			int j=i-c[1]+1;
			ans+=c[j]*pai(n-j);ans%=Mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(f)
	{
		cout<<pai(n-1);
		return 0;
	}
	ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(nd[i]==0||cnt>=c[d[i]]) cnt++;
			if(i-cnt>=m){
				ans=(ans+1)%Mod;
				break;
			}
		}
	}while(next_permutation(d+1,d+1+n));
	cout<<ans<<endl;
	return 0;
}
