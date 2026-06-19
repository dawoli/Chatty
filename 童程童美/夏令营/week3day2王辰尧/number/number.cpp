#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("nember.out","w",stdout);
	int m,n,cnt=0,c=-1000;
	bool flag=false;
	cin>>m>>n;
	int a[m+1],b[n+1];
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(b[i]==a[j]){cnt=0;continue;}
		if(cnt>0&&b[i]!=c)cnt=0;
		if(cnt>0&&b[i]==c)cnt++;
		if(cnt==0&&b[i]!=c)cnt++;
		if(cnt>=2){cout<<b[i]<<' ';flag=true;}
		c=b[i];
	}
	if(flag=false)cout<<'?';
	return 0;
} 
