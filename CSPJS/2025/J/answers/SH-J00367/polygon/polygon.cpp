#include <bits/stdc++.h>
using namespace std;
int n,a[5000];
long long sum=0,maxa,t=0,j=1;
int f(int i,int m,int j){
	if(m<=0)return 0;
	for(j;j<i;j++){
		sum+=a[j];
		if(sum>maxa*2){
			t++;
		}
		f(i,m-1,j+1);
		sum-=a[j];
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n);
	for(int i=n;i>=3;i--){
		sum=0;
		maxa=a[i];
		sum+=maxa;
		f(i,i,j);	 
	}
	cout<<t;
	return 0; 
} 
