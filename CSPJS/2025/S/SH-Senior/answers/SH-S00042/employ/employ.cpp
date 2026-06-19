#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],cnt=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) b[i]=i;
	do
	{
		int l=0,ans=0;
		for(int j=1;j<=n;j++)
		{
			int i=b[j];
			if(s[j-1]=='0') l++;
			else
			{
				if(l>=a[i]) l++;
				else ans++;
			}
		}
		if(ans>=m) cnt++;
	}while(next_permutation(b+1,b+n+1));
	cout<<cnt<<endl;
	return 0;
}
