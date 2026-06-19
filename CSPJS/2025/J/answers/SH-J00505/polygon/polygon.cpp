#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[60000];
const auto dz=a+1;
const auto tz=a+1+5000;
int maxa(int a,int b){
	if(a>=b) return a;
	else return b;
}
int cnt(ll sum,ll max){
	if(dz==tz){
		if(max==-1){
			return 0; 
		}
		if(sum>2*max){
			return 1;
		}
		else{
			return 0;
		}
	}
	int dz1=*dz;
	dz1++;
	*dz=dz1; 
	return cnt(sum+*dz,maxa(max,*dz))+cnt(sum,max)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;

	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
	sort(a+1,a+1+n);
	const auto dz=a+1;
	const auto tz=a+1+n;
	int sum=cnt(0,-1);
	cout<<sum; 
	return 0;
}
