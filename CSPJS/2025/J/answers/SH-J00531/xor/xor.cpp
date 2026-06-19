#include <bits/stdc++.h> 
using namespace std;
long long a[500005],ans,b,c,d,e,f,g,h,k,max_a,n;
string sk,s[500005],S,st,str;
char ch;
int main()
{
	cin>>n>>k;
	d=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		max_a=max(a[i],max_a);
		d*=2;
	}
	while(max_a>0)
	{
		max_a/=2;
		b++;
	}
	for(int i=0;i<n;i++)
	{
		while(a[i]>0)
		{
			ch=a[i]%2+'0';
			s[i]=ch+s[i];
			a[i]/=2;
		}
		while(s[i].length()<b)s[i]='0'+s[i];
	}
	while(k>0)
	{
		ch=k%2+'0';
		sk=sk+ch;
		k/=2;
	}
	while(sk.length()<b)sk='0'+sk;
	for(int i=0;i<n;i++)
	{
		S=s[i];
		for(int j=0;j<n-i;j++)
		{
			str=st;
			for(int l=0;l<s[i].length();l++)
			{
				if(S[l]==s[i+j][l])str=str+'0';
				else str=str+'1';
			}
			while(str.length()<b)str[i]='0'+str[i];
			S=str;
			if(str==sk)c++;
		}
	}
	cout<<c;
	return 0;
}
