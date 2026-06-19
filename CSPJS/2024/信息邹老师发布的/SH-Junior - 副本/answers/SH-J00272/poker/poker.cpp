#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
map<char,ll>s;
char a,b;
bool exist[4][14];
ll num(char ch)
{
	switch(ch)
	{
		case 'A':return 1;
		case 'T':return 10;
		case 'J':return 11;
		case 'Q':return 12;
		case 'K':return 13;
		default:return ch-'0';
	}
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld\n",&n);
	s['D']=0,s['C']=1,s['H']=2,s['S']=3;
	for(ll i=1;i<=n;++i)a=getchar(),b=getchar(),getchar(),exist[s[a]][num(b)]=1;
	for(ll i=0;i<4;++i)for(ll j=1;j<=13;++j)ans+=exist[i][j];
	printf("%lld\n",52-ans);
	return 0;
}

