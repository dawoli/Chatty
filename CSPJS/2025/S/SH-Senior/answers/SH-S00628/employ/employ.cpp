#include<bits/stdc++.h>
using namespace std;
const int moD=998244353;
int n,m,c[505],p=0;bool fla=true,fla2=false;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)p++;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')fla=false;
		if(s[i]=='1')fla2=true;
	}
	if(fla)
	{
		if(p<m)
		{
			cout<<0<<endl;
			return 0;
		}
		long long a=1,b=1;
		for(int i=2;i<=n;i++)
			a=a*i%moD;
		cout<<a%moD<<endl;
		return 0;
	}
	if(m==1)
	{
		int ans=0;
		if(!fla)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
