#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s; 
int n;
int num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	if(n==1)
	{
		cout<<s;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i] && s[i]<='9') num[++cnt]=s[i]-'0';
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
} 
