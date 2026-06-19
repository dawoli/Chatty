#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(i==1||s[i]!=s[i-1])
			ans++;
	cout<<52-ans<<endl;
	return 0;
}

