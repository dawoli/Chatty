#include <bits/stdc++.h>
using namespace std;

struct st{
	int af,l,bf;
} s[200001];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		for(int j=0;j<a.length();j++)
		{
			if(a[j]=='b') break;
			else s[i].af++;
		} 
		for(int j=0;j<b.length();j++)
		{
			if(b[j]=='b') break;
			else s[i].bf++;
		}
		s[i].l=a.length();
	}
	
	while(q--)
	{
		long long ans=0;
		string a,b;
		int at=0,bt=0;
		cin>>a>>b;
		int lt=a.length();
		for(int j=0;j<a.length();j++)
		{
			if(a[j]=='b') break;
			else at++;
		} 
		for(int j=0;j<b.length();j++)
		{
			if(b[j]=='b') break;
			else bt++;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(s[i].af-s[i].bf==at-bt && at>=s[i].af && bt>=s[i].bf && lt-at>=s[i].l-s[i].af && lt-bt>=s[i].l-s[i].af)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
