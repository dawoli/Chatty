#include<bits/stdc++.h>
using namespace std;
int d[54],c[54],h[54],s[54];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		int dianshu=0;
		if(a[1]=='A') dianshu=1;
		else if(a[1]=='T') dianshu=10;
		else if(a[1]=='J') dianshu=11;
		else if(a[1]=='Q') dianshu=12;
		else if(a[1]=='K') dianshu=13;
		else if(a[1]>='2'&&a[1]<='9') dianshu=a[1]-'0';
		if(a[0]=='D') d[dianshu]=1;
		if(a[0]=='C') c[dianshu]=1;
		if(a[0]=='H') h[dianshu]=1;
		if(a[0]=='S') s[dianshu]=1;
	}
	int sum=0;
	for(int i=1;i<=13;i++)
	{
		if(!d[i]) sum++;
		if(!c[i]) sum++;
		if(!h[i]) sum++;
		if(!s[i]) sum++;
	}
	cout<<sum;
	return 0;
}
