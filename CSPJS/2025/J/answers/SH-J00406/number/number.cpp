#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll a[N];
ll cnt=0;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt++]=s[i]-48;
		}
	}
	sort(a+0,a+cnt,cmp);
	for(ll i=0;i<cnt;i++) cout<<a[i];
	return 0;
}
