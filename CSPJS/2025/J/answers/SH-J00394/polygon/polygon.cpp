#include <bits/stdc++.h> 
using namespace std;
const int N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001],b[5001],sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=500;i++){
		for(int j=i-2;j>=1;j--){
			for(int z=1;z<=j;z++){
				b[i]+=z;
			}	
		}
		b[i]%=N;
	}
	if(sum==1){
		cout<<b[n];
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
