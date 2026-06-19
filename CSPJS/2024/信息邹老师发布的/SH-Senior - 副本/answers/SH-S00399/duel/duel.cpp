#include<bits/stdc++.h>
using namespace std;
int n, a[100005], p, ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n);
	p=1,ans=n;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[p])
		{
	    	ans--;
	    	p++;
		}
	}
	cout<<ans;
	return 0;
}
