#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;
ll n,hs,sz,cnt=0,ans;
bool f[15][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		if(str[0]=='D') hs=1;
		else if(str[0]=='C') hs=2;
		else if(str[0]=='H') hs=3;
		else hs=4;
		if(str[1]=='A') sz=1;
		else if(str[1]=='2') sz=2;
		else if(str[1]=='3') sz=3;
		else if(str[1]=='4') sz=4;
		else if(str[1]=='5') sz=5;
		else if(str[1]=='6') sz=6;
		else if(str[1]=='7') sz=7;
		else if(str[1]=='8') sz=8;
		else if(str[1]=='9') sz=9;
		else if(str[1]=='T') sz=10;
		else if(str[1]=='J') sz=11;
		else if(str[1]=='Q') sz=12;
		else sz=13;
		if(f[hs][sz]==0)
		{
			cnt++;
			f[hs][sz]=1;
		}
	}
	ll ans;
	ans=52-cnt;
	printf("%lld",ans);
	return 0;
} 
