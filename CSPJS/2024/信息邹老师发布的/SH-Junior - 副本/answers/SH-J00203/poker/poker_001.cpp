#include<bits/stdc++.h>
using namespace std;
string s[1024];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	sort(s,s+n);
	for(int i=1;i<=n;i++)if(s[i]!=s[i-1])sum++;
	cout<<52-sum<<endl;
	return 0;
}
