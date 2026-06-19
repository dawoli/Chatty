#include<bits/stdc++.h>
#define int long long
#define ll long long
#define db long long
using namespace std;
const int N=2e5,len=5e6,p=1e9+7,Digit=30;
int n,q;
//string s1[N+10],s2[N+10];
string s1,s2;
int Ha1[N+10],Ha2[N+10];
int si[N+10];
int ha1[len+10],ha2[len+10];
int q_m(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1) ret*=x,ret%=p;
		x*=x,x%=p;
		y>>=1;
	}
	return ret;
}
int work1(int l,int r)
{
	if(l>r) return 0;
	int Len=r-l+1;
	return ((ha1[r]-ha1[l-1]*q_m(Digit,Len))%p+p)%p;
}
int work2(int l,int r)
{
	if(l>r) return 0;
	int Len=r-l+1;
	return ((ha2[r]-ha2[l-1]*q_m(Digit,Len))%p+p)%p;
}
void work()
{
	int ret=0;
	cin>>s1>>s2;
	int m=s1.size();
	for(int i=1;i<=m;i++)
	{
		ha1[i]=ha1[i-1]*Digit+s1[i-1]-'a';
		ha2[i]=ha2[i-1]*Digit+s2[i-1]-'a';
	}
//	cout<<work2(1,m)<<endl;;
	for(int i=1;i<=n;i++)
	{
		int l=si[i];
		for(int j=1;j+l-1<=m;j++)
		{
			if(Ha1[i]!=work1(j,j+l-1)||Ha2[i]!=work2(j,j+l-1))
			{
//				cout<<"aaaa";
				continue;
			}
			if(work1(1,j-1)!=work2(1,j-1)) 
			{
				continue;
			}
			if(work1(j+l,m)!=work2(j+l,m))
			{
				continue;
			}
			ret++;
		}
	}
	cout<<ret<<endl;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
//		cin>>s1[i]>>s2[i];
        cin>>s1>>s2;
		int siz=s1.size();
		si[i]=siz;
		for(int j=0;j<siz;j++)
		{
			Ha1[i]=Ha1[i]*Digit+s1[j]-'a'; Ha1[i]%=p;
			Ha2[i]=Ha2[i]*Digit+s2[j]-'a'; Ha2[i]%=p;
		}
	}
	while(q--)
	{
		work();
	}
	return 0;
}
