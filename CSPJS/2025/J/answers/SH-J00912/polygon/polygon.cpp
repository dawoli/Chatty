#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int N=998244353;
int n;
long long hei[5005]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int tmp=1;
	for(int i=1;i<=5001;i++){
		tmp*=i%N;
		hei[i]=tmp;
	}
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
//			if(tmp>a[n])
//			{
//				continue;
//			}
			int ed=lower_bound(a+1,a+1+n,a[i]+a[j])-a-1;
			int st=upper_bound(a+1,a+1+n,a[j]-a[i])-a;
			ans+=hei[ed-st]%N;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

