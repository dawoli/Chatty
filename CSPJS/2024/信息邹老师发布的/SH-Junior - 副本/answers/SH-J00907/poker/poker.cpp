#include<bits/stdc++.h>
using namespace std;
int n,a[20]/*ºÚÌÒ*/,b[20]/*ºìÌÒ*/,c[20]/*Ã·»¨*/,d[20]/*·½¿é*/,cnt;
string s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='D')
		{
			if(s[1]=='A') d[1]++;
			else if(s[1]=='T') d[10]++;
			else if(s[1]=='J') d[11]++;
			else if(s[1]=='Q') d[12]++;
			else if(s[1]=='K') d[13]++;
			else d[s[1]-'0']++;
		}
		else if(s[0]=='C')
		{
			if(s[1]=='A') c[1]++;
			else if(s[1]=='T') c[10]++;
			else if(s[1]=='J') c[11]++;
			else if(s[1]=='Q') c[12]++;
			else if(s[1]=='K') c[13]++;
			else c[s[1]-'0']++;
		}
		else if(s[0]=='H')
		{
			if(s[1]=='A') b[1]++;
			else if(s[1]=='T') b[10]++;
			else if(s[1]=='J') b[11]++;
			else if(s[1]=='Q') b[12]++;
			else if(s[1]=='K') b[13]++;
			else b[s[1]-'0']++;
		}
		else
		{
			if(s[1]=='A') a[1]++;
			else if(s[1]=='T') a[10]++;
			else if(s[1]=='J') a[11]++;
			else if(s[1]=='Q') a[12]++;
			else if(s[1]=='K') a[13]++;
			else a[s[1]-'0']++;
		}
	}
	for(int i=1;i<=13;i++)
	{
		if(a[i]==0) cnt++;
		if(b[i]==0) cnt++;
		if(c[i]==0) cnt++;
		if(d[i]==0) cnt++;
	}
	cout<<cnt;
}
