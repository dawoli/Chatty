#include<iostream>
using namespace std;
long long a[5005],n,ans,mod=998244353;
long long t[5005],sum[5005];
bool _;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			_=1;
		}
	}
	if(_==0){
		for(int i=1;i<=5000;i++){
			t[i]=t[i-1]+i;
			sum[i]=sum[i-1]+t[i];
		}
		for(int i=3;i<=n;i++){
			int k=n-i+1;
			ans=(ans+sum[k]%mod)%mod;
		}
	}else{
		if(n==1){
			ans=0;
		}
		if(n==2){
			ans=0;
		}
		if(n==3){
			long long sum=0,maxa=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
				maxa=max(maxa,a[i]);
			}
			if(sum>2*maxa){
				ans=1;
			}
		}
		if(n==4){
			long long sum=0,maxa=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if((a[i]+a[j]+a[k])>2*max(a[i],max(a[j],a[k]))){
							ans++;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				sum+=a[i];
				maxa=max(maxa,a[i]);
			}
			if(sum>2*maxa){
				ans++;
			}
		} 
		if(n==5){
			long long sum=0,maxa=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if((a[i]+a[j]+a[k])>2*max(a[i],max(a[j],a[k]))){
							ans++;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							if((a[i]+a[j]+a[k]+a[l])>2*max(a[i],max(a[j],max(a[k],a[l])))){
								ans++;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				sum+=a[i];
				maxa=max(maxa,a[i]);
			}
			if(sum>2*maxa){
				ans++;
			}
		} 
		if(n>5){
			for(int i=1;i<=5000;i++){
				t[i]=t[i-1]+i;
				sum[i]=sum[i-1]+t[i];
			}
			for(int i=3;i<=n;i++){
				int k=n-i+1;
				ans=(ans+sum[k]%mod)%mod;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

