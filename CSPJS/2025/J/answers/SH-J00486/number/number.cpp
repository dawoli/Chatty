#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num[1000009],cnt;
string s;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned i=0;i<s.length();i++) 
	{
		char ch=s[i];
		if(!('0'<=ch&&'9'>=ch))
			continue;
		ll nm=(ll)(ch-'0');
		num[++cnt]=nm;
	}
	sort(num+1,num+cnt+1,greater<ll>());
	for(int i=1;i<=cnt;i++)
		printf("%lld",num[i]);
	printf("\n");
	return 0;
}
