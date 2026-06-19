#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],can[10000],ans,N=998244353,num1,num2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num1=0;
		num2=0;
		for(int j=a[i]+1;j<=5000;j++){
			num2+=can[j];
		}
		for(int j=5000;j>=1;j--){
			num1=a[i]+j;
			if(num1>5000){
				num1=5000;
			}
			can[num1]+=can[j];
		}
		for(int j=i-1;j>=1;j--){
			num1=a[i]+a[j];
			if(num1>5000){
				num1=5000;
			}
			can[num1]++;
		}
		ans+=num2;
		ans%=N;
		for(int j=1;j<=5000;j++){	
			can[j]%=N; 
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
