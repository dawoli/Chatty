#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10000];
long long ans=0;
void dfs(long long start,long long b,long long maxn,long long sum){
	b--;
	sum+=a[start];
	maxn=max(maxn,a[start]);
	if(b==0){
		if(sum>maxn*2){
		ans++;
		//cout<<sum<<endl;
		ans=ans%998244353;
		}
	}
	
	for(int i=start+1;i<=n;i++){
		dfs(i,b,maxn,sum);
		
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	long long flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)flag++;
	}
	if(flag==n){
		//cout<<"923";
		int f[6000]={0};
		int s[6000]={0};
		for(int i=1;i<=n-3;i++){
			f[i]=f[i-1]+1;
			
		}
		for(int i=1;i<=n-3;i++){
			s[i]=s[i-1]+f[i];
		//	cout<<s[i];
		}
		int temp=0;
		for(int i=n-3;i>=1;i--){
			ans+=s[i];
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++)dfs(j,i,-1,0);
		
		
	}
	cout<<ans;
	return 0;
}
