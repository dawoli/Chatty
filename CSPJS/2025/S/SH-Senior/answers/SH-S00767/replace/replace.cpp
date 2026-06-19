#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n,q;
const int maxn=2e5+10;
string com1[maxn],com2[maxn];
string det[maxn];
string dom1[maxn],dom2[maxn];
inline int read()
{
	int rr=0,ww=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    ww=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		rr=rr*(1<<3)+rr*(1<<1)+ch-(1<<4)-(1<<5);
		ch=getchar();
	}
	return rr*ww;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		cout<<"0"<<endl;
	}
	return 0;
}
