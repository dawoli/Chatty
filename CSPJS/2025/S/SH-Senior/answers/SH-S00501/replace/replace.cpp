#include <iostream>
#include <cstdio>
using namespace std;
int n;
int m;
long long h1[100005],h2[100005];
int len1[100005],len2[100005];
string k1[100005],k2[100005];
string pre[100005],nxt[100005];
const long long mod=998244353;
long long p[3005];
long long ca1[100005],ca2;
void work()
{
	for(int i=1;i<=n;i++) cin>>k1[i]>>k2[i];
	while(m--)
	{
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int L=s1.size();
		if(s1.size()!=s2.size()) 
		{
			cout<<0<<endl;
			continue;
		}
		s1=" "+s1;
		pre[0]="";
		nxt[L+1]="";
		for(int i=1;i<=L;i++) pre[i]=pre[i-1]+s1[i];
		for(int i=L;i>=1;i--) nxt[i]=nxt[i+1]+s1[i];
		for(int i=1;i<=L;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int len=k1[j].size();
				if(i+len-1>L) continue;
				string tmp="",res="";
				for(int k=i;k<=i+len-1;k++) tmp+=s1[k];
				if(tmp!=k1[j]) continue;
				res=res+pre[i-1]+k2[j]+nxt[i+len];
				if(res==s2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
long long query(int l,int r)
{
	return (ca1[r]-ca1[l-1]*p[r-l+1]%mod+mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=100&&m<=100)
	{
		work();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		len1[i]=s.size();
		s=" "+s;
		for(int j=1;j<=len1[i];j++) h1[i]=(h1[i]*31%mod+s[j]-'a')%mod;
		cin>>s;
		len2[i]=s.size();
		s=" "+s;
		for(int j=1;j<=len2[i];j++) h2[i]=(h2[i]*31%mod+s[j]-'a')%mod;
	}
	p[0]=1;
	for(int i=1;i<=3000;i++) p[i]=p[i-1]*31%mod;
	while(m--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int len=t1.size();
		t1=" "+t1,t2=" "+t2;
		ca1[0]=0,ca2=0;
		for(int i=1;i<=len;i++) ca1[i]=(ca1[i-1]*31%mod+t1[i]-'a')%mod;
		for(int i=1;i<=len;i++) ca2=(ca2*31%mod+t2[i]-'a')%mod;
		for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+len1[j]-1>len) continue;
				long long res;
				if(query(i,i+len1[j]-1)!=h1[j]) continue;
				res=(ca1[len]-query(i,i+len1[j]-1)*p[len-(i+len1[j]-1)]%mod+mod)%mod;
				res=(res+h2[j]*p[len-(i+len1[j]-1)]%mod)%mod;
				if(res==ca2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
