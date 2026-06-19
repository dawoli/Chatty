#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
const int maxn=100006;
struct Edge
{
	int a,b;
}e[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int l[maxn],m[maxn];
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=0;j<s1.length();j++)
		{
			if(s1[j]=='b') l[i]=j;
			if(s2[j]=='b') m[i]=j;
			if(l[i]>=0&&m[i]>=0) break;
		}
	}
	while(q--)
	{
		int ans=0;
		int p=-1,o=-1;
		cin>>t1>>t2;
		for(int i=0;i<t1.length();i++)
		{
			if(t1[i]=='b') p=i;
			if(t2[i]=='b') o=i;
			if(p>=0&&o>=0) break;
		}
		for(int j=1;j<=n;j++)
		{
			if(p-o==l[i]-m[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
