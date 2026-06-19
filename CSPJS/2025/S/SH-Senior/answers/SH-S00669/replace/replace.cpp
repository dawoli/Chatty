#include <bits/stdc++.h>
using namespace std;
int n,q,ans,cnt;
string s[200005][3],t[200005][3];
string repl(string aa,string bb,int k)
{
	int la=aa.size(),lb=bb.size();
	string x,y,z;
	for (int i=0;i<k;i++)
	{
		x+=aa[i];
	}
	for (int i=k;i<k+lb;i++)
	{
		y+=bb[i-k];
	}
	for (int i=k+lb;i<la;i++)
	{
		z+=aa[i];
	}
	return x+y+z;
}
void find(int u,int v)
{
	int la=t[u][1].size(),lb=s[v][1].size();
	string a=t[u][1],b=s[v][1],c=t[u][2],d=s[v][2];
	for (int i=0;i<=la-lb;i++)
	{
		int t=1;
		for (int j=0;j<lb;j++)
		{
			if (a[i+j]!=b[j]) t=0;
		}
		if (t==1)
		{
			string cc=a;
			cnt++;
			a=repl(a,d,i);
			if (a==c) ans++;
			a=cc;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for (int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	for (int i=1;i<=q;i++)
	{
		for (int j=1;j<=n;j++)
		{
			find(i,j);
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
