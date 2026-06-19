#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long a[5010];
long long df[5010];
long long ans;
void dfs(int k){
	if(k==n+1){
		long long sum=0,maxx=0,sumal=0;
		for(int i=1;i<=n;i++){
			sum+=df[i];
			maxx=max(maxx,df[i]*a[i]);
			sumal+=(df[i]*a[i]);
		}//cout<<sum<<" "<<maxx<<" "<<sumal<<endl;
		if(sum<3)return ;
		if(sumal>maxx*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}for(int i=0;i<=1;i++){
		df[k]=i;
		dfs(k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)u=1;
	}if(n<=20){
		dfs(1);
		cout<<ans;
	}else if(u==0){
		long long o1=n,o2=n*(n-1)/2;
		if(n%2==1){
			ans+=1;
			for(int i=1;i<=n/2;i++){
				long long sum1=1,sum2=1;
				for(int j=1;j<=n;j++){
					sum1*=j;
					if(j>=i)break;
				} for(int j=n;j>=1;j--){
					sum2*=j;
					if((n-j+1)>=i)break;
				} ans+=sum2/sum1;
				ans%=998244353;
			}cout<<ans*2-o1-o2-1;
			ans%=998244353;
		}else{
			ans+=1;
			for(int i=1;i<=n/2;i++){
				long long sum1=1,sum2=1;
				for(int j=1;j<=n;j++){
					sum1*=j;
					if(j>=i)break;
				} for(int j=n;j>=1;j--){
					sum2*=j;
					if((n-j+1)>=i)break;
				} ans+=sum2/sum1;
				ans%=998244353;
				if(i==n/2-1)ans*=2;
				ans%=998244353;
			}cout<<ans-o1-o2-1;
		}
		
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
