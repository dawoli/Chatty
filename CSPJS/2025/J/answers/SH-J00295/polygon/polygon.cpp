#include<bits/stdc++.h>
using namespace std;
int a[6000]={};
int modnum=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==3){
		if((a[0]+a[1]>a[2])&&(a[2]+a[1]>a[0])&&(a[0]+a[2]>a[1]))cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long sum=n-2;
	cout<<sum%modnum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
