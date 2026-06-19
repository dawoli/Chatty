#include<bits/stdc++.h>
using namespace std;
long long ans = 52,n,rn;
bool b[53];
char c,num;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>c>>num;
		if(num == 'A') rn = 1;
		else if(num == 'T') rn = 10;
		else if(num == 'J') rn = 11;
		else if(num == 'Q') rn = 12;
		else if(num == 'K') rn = 13;
		else rn = (long long)(num - '0');
		if(c == 'D') rn += 0;
		else if(c == 'C') rn += 13;
		else if(c == 'H') rn += 26;
		else if(c == 'S') rn += 39;
		if(!b[rn])
		{
			b[rn] = 1;
			ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
