#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans;
int a[200005];
map<int,int> d;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		d.clear();
		for(int i=1;i<=n;i++)
		{
			d[a[i]]++;
		}
		ans=0;
		for(int i=1;i<=*max_element(a+1,a+n+1);i++)
		{
			if(d[i]>1)
				ans+=(d[i]-1)*i;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
