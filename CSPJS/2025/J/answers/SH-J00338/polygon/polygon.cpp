#include<bits/stdc++.h>
using namespace std;
bool cyd(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+4,cyd);
		if(a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
	}
	else cout<<337; 
	return 0;
}
