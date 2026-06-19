#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5009;
long long l[N],r[N],sum[N],k[N];
long long maxx=0,g=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){cin>>l[i];r[i]=r[i-1]+l[i];maxx=max(maxx,l[i]);}
	
	if(n==3)
	{
		sort(l+1,l+1+n);
		if(l[1]+l[2]>l[3]){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else if(n<3)
	{
		cout<<0<<endl;
	}
	else if(maxx==1)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			ans=((ans*2)%mod)%mod;	
		}
		ans=ans-n-1;
		ans=(ans+mod)%mod;
		cout<<ans<<endl;
	}
	else
	{
		sort(l+1,l+1+n);
		if(l[1]+l[2]>l[3]){
			k[r[3]]=1;
			sum[3]=1;
		}
		for(long long i=4;i<=n;i++)
		{
			if(l[i]*2>=r[i])
			{
				continue;
			}
			else
			{
				k[r[i]]++;sum[i]++;
				for(long long j=1;j<=i;j++)
				{
					if(2*l[i]<r[i]-l[j])
					{
						k[r[i]-l[j]]=(k[r[i]]+k[r[i]-l[j]])%mod;
						sum[i]+=k[r[i]-l[j]];
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			g=(g+sum[i])%mod;
		}
		cout<<g<<endl;
	}
	return 0;
} 
