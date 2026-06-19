#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n,cnt[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=cnt[i];j++) cout<<i;
	cout<<endl;
	return 0;
}
