#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a[100005],minn,t,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	minn=a[1],t=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>minn)
		{
			ans++;
			minn=a[++t];
		}
	}
	cout<<n-ans<<endl;
	return 0;
}


