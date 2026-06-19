#include<bits/stdc++.h>
using namespace std;
int a[5011];
int p[5011];
void init(){
	long long ans;
	int n;
	int m=0,z=0;//分别为最大值和总和 
	cin>>n;
	int f1=1;//判断是否全部为1 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
		m=max(m,a[i]);
		z+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];	
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			z+=a[i];
			m=max(m,a[i]);
		}
		if(z>2*m){
			cout<<1;
			return;
		}
		else{
			cout<<0;
			return;
		}
	}
	if(f1=1){
		for(int i=3;i<n;i++){
			if(n%i==0){
				ans+=n-i+2;
			}
			else{
				ans+=n-i+1;
			}
		}
		ans++;
		cout<<ans%998244353;
		return;
	}
	
	
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(p[j-i+1]>2*a[j]){
				ans++;
			}
			if(ans>=998244353)ans%=998244353;
		}
	}
	cout<<ans%998244353;
	return;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
