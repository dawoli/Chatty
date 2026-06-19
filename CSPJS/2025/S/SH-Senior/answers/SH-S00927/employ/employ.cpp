#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int n,m;
int s[501];
int c[501];

inline int quanpailie(int a)
{
	int shang=1;
	for(int i=2;i<a;i++)
	{
		shang*=i;
		shang%=mod;
	}
	return shang;
}

int main()
{
	ifstream in("employ.in");
	ofstream out("employ.out");
	in>>n>>m;
	string s_;
	in>>s_;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(s_[i]-'0');
	}
	for(int i=1;i<=n;i++)
	{
		in>>c[i];
	}
	if(s[n]==n)
	{
		out<<quanpailie(n);
	}
	else if(m==1)
	{
		
	}
	return 0;
}
