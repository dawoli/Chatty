#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	long long a[200000]={0};
	long long n,flag=0,flag2=0;
	cin>>n;
	long long ans,temp=0,sum=0;
	cin>>ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)flag++;
		if(a[i]==1&&a[i]==a[i-1])flag2+=2;
		
	}
	if(ans==0&&flag==n){
		cout<<n/2;
		return 0;
	}
	else if(ans<=1){
		if(ans==0)cout<<n-flag+flag2/2;
		else cout<<flag;
		return 0;
	}
	return 0;
}
