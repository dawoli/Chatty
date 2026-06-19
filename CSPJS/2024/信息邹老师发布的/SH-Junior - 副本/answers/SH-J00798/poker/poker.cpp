#include<iostream>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char a[n+1][2]={};
	bool d[14]={},c[14]={},h[14]={},s[14]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		if(a[i][0]=='D')
		{
			if(a[i][1]>='2'&&a[i][1]<='9') d[a[i][1]-'0']=1;
			else if(a[i][1]=='A') d[1]=1;
			else if(a[i][1]=='T') d[10]=1;
			else if(a[i][1]=='J') d[11]=1;
			else if(a[i][1]=='Q') d[12]=1;
			else if(a[i][1]=='K') d[13]=1;
		}
		else if(a[i][0]=='C')
		{
			if(a[i][1]>='2'&&a[i][1]<='9') c[a[i][1]-'0']=1;
			else if(a[i][1]=='A') c[1]=1;
			else if(a[i][1]=='T') c[10]=1;
			else if(a[i][1]=='J') c[11]=1;
			else if(a[i][1]=='Q') c[12]=1;
			else if(a[i][1]=='K') c[13]=1;
		}
		else if(a[i][0]=='H')
		{
			if(a[i][1]>='2'&&a[i][1]<='9') h[a[i][1]-'0']=1;
			else if(a[i][1]=='A') h[1]=1;
			else if(a[i][1]=='T') h[10]=1;
			else if(a[i][1]=='J') h[11]=1;
			else if(a[i][1]=='Q') h[12]=1;
			else if(a[i][1]=='K') h[13]=1;
		}
		else if(a[i][0]=='S')
		{
			if(a[i][1]>='2'&&a[i][1]<='9') s[a[i][1]-'0']=1;
			else if(a[i][1]=='A') s[1]=1;
			else if(a[i][1]=='T') s[10]=1;
			else if(a[i][1]=='J') s[11]=1;
			else if(a[i][1]=='Q') s[12]=1;
			else if(a[i][1]=='K') s[13]=1;
		}
	}
	int t=0;
	for(int i=1;i<=13;i++)
	{
		if(h[i]) t++;
		if(s[i]) t++;
		if(d[i]) t++;
		if(c[i]) t++;
	}
	cout<<52-t;
	return 0;
}
