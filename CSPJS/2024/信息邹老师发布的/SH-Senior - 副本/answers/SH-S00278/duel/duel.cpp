#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005]; 
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=a[1],cnt=0;
	for (int i=1;i<=n;i++)
	{
		if(a[i]==x)cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
