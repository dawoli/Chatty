#include<bits/stdc++.h>
using namespace std;
int pk[60],n;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		int m,n;
		cin>>a>>b;
		if(a=='S') m=0;
		if(a=='H') m=13;
		if(a=='D') m=26;
		if(a=='C') m=39;
		if(b>='0' && b<='9') n=b-'0';
		if(b=='T') n=10;
		if(b=='J') n=11;
		if(b=='Q') n=12;
		if(b=='K') n=13;
		if(b=='A') n=1;
		pk[m+n]=1;
	}
	int ans=0;
	for(int i=1;i<=52;i++)
	{
		if(pk[i]==0)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
