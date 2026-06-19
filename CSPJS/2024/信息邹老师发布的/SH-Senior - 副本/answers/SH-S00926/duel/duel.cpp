#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct ccc{
	int r,id;
};
ccc x[100005];
bool f[100005];
bool v[100005];
bool cmp(ccc a,ccc b)
{
	if(a.r<=b.r)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		x[i].id=i;
		x[i].r=t;
	}
	int j=2;
	sort(x+1,x+1+n,cmp);
	for(long long i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
			continue;
		}
		for(;j<=n;j++)
		{
			//cout<<"@  "<<j<<" "<<f[j]<<" "<<v[j]<<endl;
			if(f[j]==0 and x[j].r>x[i].r and v[j]==0)
			{
				f[i]=1;
				ans++;
				v[j]=1;
				//cout<<"!  "<<i<<" "<<j<<" "<<ans<<endl;
				break;
			}
		}
	}
	cout<<n-ans;
	return 0;
} 
