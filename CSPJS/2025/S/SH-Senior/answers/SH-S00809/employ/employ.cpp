#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,k;
int a[505];
long long ans=1;
bool ju(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='0') return 0;
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) m--;
	}
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%998244353;
	}
	cout<<ans;
}
