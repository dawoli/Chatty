#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define db double
using namespace std;
const int lim=10;
int tong[lim+5];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int si=s.size();
	for(int i=0;i<si;i++)
	{
		if(s[i]>='0'&&s[i]<='9') tong[s[i]-'0']++;
	}
	for(int i=9;~i;i--) 
	{
		while(tong[i]--) printf("%d",i);
	}
	return 0;
}
