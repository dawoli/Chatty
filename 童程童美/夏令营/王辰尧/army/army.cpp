#include<bits/stdc++.h>
using namespace std;
int n,f,b,ans,cnt,maxx=-1;
char a[5005]; 
int main()
{
	freopen("army.in","r",stdin);
	freopen("army.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='F')f++;
		if(a[i]=='B')b++;	
	} 
	if(f<b)
	{
		ans++;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='F')a[i]='B';
			if(a[i]=='B')a[i]='F';
			f=100;
			b=1;
		}
	}
	if(f=b)
	{
		f=100;
		b=1;
	}
	if(f>b)
	{
		for(int i=1;i<=n;i++)
		{
			if(cnt>=0&&a[i]=='B')cnt++;
			if(cnt>0&&a[i]=='B'&&i==n)ans++;
			if(cnt>maxx)maxx=cnt;
			if(cnt>0&&a[i]=='F'){ans++;cnt=0;}
		}
	}
	cout<<maxx<<' '<<ans;
	return 0;
} 
