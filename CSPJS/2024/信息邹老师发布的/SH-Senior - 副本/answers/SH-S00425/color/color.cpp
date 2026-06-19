#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,a[N],c[N];
bool check(int p,int id)
{
	for(int i=1;i<id;i++)
	{
		if((p>>(n-id))%2==(p>>(n-id+i))%2)
		{
			if(a[id]==a[id-i])
				return true;
			else
				break;
		}
	}
	return false;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		if(n<=15){
			int nPtn=(1<<n)-1;
			long long ans=0,cnt;
			for(int p=0;p<=nPtn;p++)
			{
				cnt=0;
				fill(c+1,c+1+n,0);				
				for(i=1;i<=n;i++)
					if(check(p,i))
						c[i]=a[i];
				for(i=1;i<=n;i++)
					cnt+=c[i];
				ans=max(ans,cnt);
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}

