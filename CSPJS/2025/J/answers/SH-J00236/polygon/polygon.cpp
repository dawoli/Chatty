#include <bits/stdc++.h>
using namespace std;

int n,a[5001],cnt=0;

void search(int bg,int sum,int mx,int deep)

{
	if(deep>=3 && sum>mx*2) cnt++;
	if(bg!=n)
	{
		for(int i=bg+1;i<=n;i++)
		{
			search(i, sum+a[i], max(mx,a[i]), deep+1);
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		search(i,a[i],a[i],1);
	}
	cout<<cnt%998244353;
	return 0;
} 
